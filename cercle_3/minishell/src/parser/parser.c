/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:40:34 by daavril           #+#    #+#             */
/*   Updated: 2025/03/11 17:41:36 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

int	check_is_expand(t_token **token_list, t_clone **env)
{
	t_token	*current;
	char	*cpy;

	current = *token_list;
	while (current)
	{
		cpy = ft_strdup(current->value);
		if (current->is_expand == 1)
		{
			if (!expand_string(current, env, cpy))
				return (1);
		}
		current = current->next;
		free(cpy);
	}
	return (0); // des int partout ? je pense que je me perds
}

void	do_merge(t_token **token_list, t_token *cur, char *va_prev, char *va)
{
	char	*new_value;
	t_token	*to_delete;

	to_delete = cur->prev;
	new_value = ft_strjoin(va, va_prev);
	free(to_delete->value);
	free(cur->value);
	if (cur->value_2 && cur->value_2 != to_delete->value_2) // refaire des tests de valgrind
		free(cur->value_2);
	if (to_delete->value_2)
		free(to_delete->value_2);
	cur->value = ft_strdup(new_value);
	cur->value_2 = NULL;
	if (to_delete->is_expand || cur->is_expand)
		cur->is_expand = 1;
	if (to_delete->prev)
		to_delete->prev->next = cur;
	else
		*token_list = cur;
	cur->prev = to_delete->prev;
	free(to_delete);
	free(new_value);
}


void	merge_token(t_token **token_list)
{
	t_token	*cur;

	cur = *token_list;
	while (cur)
	{
		if (cur->prev && cur->prev->space == 0 && cur->prev->type != 2 && cur->type != 2)
		{
			if (!cur->value_2 && !cur->prev->value_2)
				do_merge(token_list, cur, cur->value, cur->prev->value);
			else if (cur->value_2 && !cur->prev->value_2)
				do_merge(token_list, cur, cur->value_2, cur->prev->value);
			else if (!cur->value_2 && cur->prev->value_2)
				do_merge(token_list, cur, cur->value, cur->prev->value_2);
			else
				do_merge(token_list, cur, cur->value_2, cur->prev->value_2);
		}
		cur = cur->next;
	}
}

void	cmd_add_back(t_master **master, t_cmd *node)
{
	t_cmd	**list;

	list = &(*master)->cmd_list;
	while (*list)
		list = &(*list)->next;
	*list = node;
}

void	init_cmd_list_2(t_cmd **cmd, int i, t_token *token)
{
	(*cmd)->args = ft_calloc(i, sizeof(char *)); // ptet pas 1024 on god
	(*cmd)->infile = NULL;
	(*cmd)->outfile = NULL;
	(*cmd)->path = NULL;
	(*cmd)->append = 0;
	(*cmd)->next = NULL;
	(*cmd)->error = 0;
	if (token && token->real >= 2 && token->real <= 8)
		(*cmd)->builtins = token->real;
	else
		(*cmd)->builtins = 0;
	printf("cmd_builtins = %d\n", (*cmd)->builtins);
	// printf("cmd_real = %d\n", token->real);
}

void	init_cmd_list(t_master **master, int i)
{
	t_token	*cur;
	t_cmd	*new_cmd;

	cur = (*master)->token_list;
	while (cur)
	{
		i = 1;
		while(cur && cur->real != PIPE)
		{
			i++;
			cur = cur->next;
		}
		if (cur->real == PIPE)
			cur = cur->next;
		if (cur == NULL)
			break ;
		// cur = cur->next;
		new_cmd = malloc(sizeof(t_cmd));
		if (!new_cmd)
			return ;
		init_cmd_list_2(&new_cmd, i, cur); //verifier si cur est NULL ou pas?
		cmd_add_back(master, new_cmd);
	}
}

void	add_cmd(t_cmd *node, char *va, int *i)
{
	char	*path;
	char	**split_path;
	char	*full_path;
	int		j;

	node->args[*i] = ft_strdup(va);
	path =  getenv("PATH"); //belek ici faut prendre a partir de notre copie??
	split_path = ft_split(path, ':');
	j = 0;
	while(split_path[j])
	{
		full_path = ft_strjoin(split_path[j], "/");
		full_path = ft_strjoin(full_path, va);
		if (access(full_path, X_OK) == 0)
		{
			node->path = full_path;
			(*i)++;
			return ;
		}
		j++;
	}
	node->error = 0;
	(*i)++;
}

void	parse_cmd(t_master **master)
{
	int	i;
	t_token	*cur;
	t_cmd	*cmd_list;

	i = 0;
	cur = (*master)->token_list;
	init_cmd_list(master, 0);
	cmd_list = (*master)->cmd_list;
	while (cur && cmd_list)
	{
		if (cur->value_2 == NULL)
			add_cmd(cmd_list, cur->value, &i);
		else
			add_cmd(cmd_list, cur->value_2, &i);
		cur = cur->next;
		if (cur && cur->real == PIPE)
		{
			cmd_list = cmd_list->next;
			cur = cur->next;
			i = 0;
		}
	}
	/*TEST---------------*/
	// i = 0;
	// t_cmd	*g;
	// g = (*master)->cmd_list;
	// while (g)
	// {
	// 	while(g->args[i])
	// 	{
	// 		printf("split[%d] : %s\n", i, g->args[i]);
	// 		printf("cmd_path = %s\n", g->path);
	// 		i++;
	// 	}
	// 	g = g->next;
	// 	i = 0;
	// }
	/*-------------------*/
}


int	parser(t_master *master)
{
	if (check_is_expand(&master->token_list, &master->env_clone) == 1)
		return (printf("PROBLEME EXPAND\n"), 1);
	merge_token(&master->token_list);
	directory_check(&master->token_list);
	parse_cmd(&master);
	return (0);
}
