/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:40:34 by daavril           #+#    #+#             */
/*   Updated: 2025/03/12 16:59:49 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	if (cur->value_2 && cur->value_2 != to_delete->value_2)
		// refaire des tests de valgrind
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
		if (cur->prev && cur->prev->space == 0 && cur->prev->type != 2
			&& cur->type != 2)
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
	(*cmd)->args = ft_calloc(i + 1, sizeof(char *)); // ptet pas 1024 on god
	(*cmd)->infile = NULL;
	(*cmd)->outfile = NULL;
	(*cmd)->path = NULL;
	(*cmd)->append = 0;
	(*cmd)->nb_heredoc = 0;
	(*cmd)->next = NULL;
	(*cmd)->error = 0;
	if (token && token->real >= 2 && token->real <= 8)
		(*cmd)->builtins = token->real;
	else
		(*cmd)->builtins = 0;
	// printf("cmd_builtins = %d\n", (*cmd)->builtins);
	// // printf("cmd_real = %d\n", token->real);
}

void	init_cmd_list(t_master **master, int i)
{
	t_token	*cur;
	t_cmd	*new_cmd;

	cur = (*master)->token_list;
	while (cur)
	{
		i = 1;
		while (cur->next && cur->next->real != PIPE)
		{
			i++;
			cur = cur->next;
		}
		new_cmd = malloc(sizeof(t_cmd));
		if (!new_cmd)
			return ;
		init_cmd_list_2(&new_cmd, i, cur); // verifier si cur est NULL ou pas?
		cmd_add_back(master, new_cmd);
		cur = cur->next;
		if (cur == NULL)
			break ;
	}
}

void	add_cmd(t_cmd *node, char *va, int *i)
{
	char	*path;
	char	**split_path;
	char	*full_path;
	int		j;

	// if (ft_strncmp(va, "<", 1) == 0 || ft_strncmp(va, ">", 1) == 0
	// 	|| ft_strncmp(va, "<<", 1) == 0 || ft_strncmp(va, ">>", 1) == 0)
	// 	return ;
	node->args[*i] = ft_strdup(va);
	path = getenv("PATH"); // belek ici faut prendre a partir de notre copie??
	split_path = ft_split(path, ':');
	j = 0;
	while (split_path[j])
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

void	fill_redir(t_cmd **cmd, int in, t_token **token)
{
	if (in == 0)
	{
		if ((*cmd)->outfile != NULL)
			free((*cmd)->outfile);
		if (!(*token)->value_2)
			(*cmd)->outfile = ft_strdup((*token)->value);
		else
			(*cmd)->outfile = ft_strdup((*token)->value_2);
		if ((*token)->prev->real == APPEND)
			(*cmd)->append = 1;
		else
			(*cmd)->append = 0;
	}
	else
	{
		if ((*cmd)->infile != NULL)
			free((*cmd)->infile);
		if (!(*token)->value_2)
			(*cmd)->infile = ft_strdup((*token)->value);
		else
			(*cmd)->infile = ft_strdup((*token)->value_2);
		if ((*token)->prev->real == HEREDOC)
			(*cmd)->nb_heredoc += 1;
	}
}

void	outinfile_checker(t_cmd **cmd)
{
	if ((*cmd)->outfile != NULL)
	{
		if (access((*cmd)->outfile, F_OK) == 0 && access((*cmd)->outfile,
				R_OK) != 0)
			(*cmd)->error = 1;
	}
	if ((*cmd)->infile != NULL)
	{
		if (access((*cmd)->infile, F_OK) != 0)
			(*cmd)->error = 1;
		else if (access((*cmd)->infile, W_OK) != 0)
			(*cmd)->error = 1;
	}
}

void	handle_redir(t_master **master)
{
	t_token	*cur;
	t_cmd	*cmd_list;

	if (!master || !*master)
		return ;
	cur = (*master)->token_list;
	cmd_list = (*master)->cmd_list;
	while (cur && cmd_list)
	{
		if (cur->real == REDIR_IN || cur->real == HEREDOC)
			fill_redir(&cmd_list, 1, &cur->next);
		else if (cur->real == REDIR_OUT || cur->real == APPEND)
			fill_redir(&cmd_list, 0, &cur->next);
		outinfile_checker(&cmd_list);
		cur = cur->next;
		if (cur && cur->real == PIPE)
		{
			cmd_list = cmd_list->next;
			cur = cur->next;
		}
	}
}

// void	handle_redir(t_master **master)
// {
// 	t_token	*cur;
// 	t_cmd	*cmd_list;

// 	cur = (*master)->token_list;
// 	cmd_list = (*master)->cmd_list;
// 	while (cur && cmd_list)
// 	{
// 		if (cur->real == REDIR_IN)
// 			fill_redir(&cmd_list, 1, &cur->next);
// 		else if (cur->real == HEREDOC)
// 			fill_redir(&cmd_list, 1, &cur->next);
// 		else if (cur->real == APPEND)
// 			fill_redir(&cmd_list, 0, &cur->next);
// 		else if (cur->real == REDIR_OUT)
// 			fill_redir(&cmd_list, 0, &cur->next);
// 		outinfile_checker(&cmd_list);
// 		cur = cur->next;
// 		if (cur && cur->real == PIPE)
// 		{
// 			cmd_list = cmd_list->next;
// 			cur = cur->next;
// 		}
// 	}
// }

void	parse_cmd(t_master **master)
{
	int		i;
	t_token	*cur;
	t_cmd	*cmd_list;
	t_cmd	*g;

	i = 0;
	cur = (*master)->token_list;
	init_cmd_list(master, 0);
	cmd_list = (*master)->cmd_list;
	while (cur && cmd_list)
	{
		if (cur->value_2 == NULL)
			add_cmd(cmd_list, cur->value, &i);
		else if (cur->value_2 != NULL)
			add_cmd(cmd_list, cur->value_2, &i);
		cur = cur->next;
		if (cur && cur->real == PIPE)
		{
			cmd_list = cmd_list->next;
			cur = cur->next;
			i = 0;
		}
	}
	handle_redir(master);
	/*TEST---------------*/
	i = 0;
	g = (*master)->cmd_list;
	while (g)
	{
		while (g->args[i])
		{
			printf("split[%d] : %s\n", i, g->args[i]);
			i++;
		}
		printf("cmd outfile : %s\n", g->outfile);
		printf("cmd infile : %s\n", g->infile);
		printf("append value %d\n", g->append);
		printf("heredoc value %d\n", g->nb_heredoc);
		printf("error value : %d\n", g->error);
		g = g->next;
		i = 0;
		/*-------------------*/
	}
}

int	parser(t_master *master)
{
	if (!master)
		return (1);
	if (check_is_expand(&master->token_list, &master->env_clone) == 1)
		return (printf("PROBLEME EXPAND\n"), 1);
	merge_token(&master->token_list);
	directory_check(&master->token_list);
	parse_cmd(&master);
	return (0);
}
