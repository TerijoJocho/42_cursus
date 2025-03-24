/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:40:34 by daavril           #+#    #+#             */
/*   Updated: 2025/03/24 17:03:12 by daavril          ###   ########.fr       */
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

void	add_cmd(t_cmd *node, char *va, int *i, int flag)
{
	char	*path;
	char	**split_path;
	char	*full_path;
	int		j;

	if (flag == 1)
		return ;
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
	// node->error = 0;
	(*i)++;
}

void	parse_cmd(t_master **master, int i, int flag)
{
	t_token	*cur;
	t_cmd	*cmd_list;

	cur = (*master)->token_list;
	init_cmd_list(master, 0);
	cmd_list = (*master)->cmd_list;
	while (cur && cmd_list)
	{
		if (cur->type == 2)
			flag = 1;
		if (cur->value_2 == NULL)
			add_cmd(cmd_list, cur->value, &i, flag);
		else if (cur->value_2 != NULL)
			add_cmd(cmd_list, cur->value_2, &i, flag);
		cur = cur->next;
		if (cur && cur->real == PIPE)
		{
			cmd_list = cmd_list->next;
			cur = cur->next;
			i = 0;
			flag = 0;
		}
	}
	handle_redir(master, 0, 0, 0);
	/*TEST---------------*/
	// t_cmd	*g;

	// i = 0;
	// int	k = -1;
	// g = (*master)->cmd_list;
	// while (g)
	// {
	// 	while (g->args[i])
	// 	{
	// 		printf("split[%d] : %s\n", i, g->args[i]);
	// 		while (g->outfile[k++])
	// 			printf("cmd outfile[%d] : %s\n", k, g->outfile[k]);
	// 		k = -1;
	// 		while (g->infile[k++])
	// 			printf("cmd infile[%d] : %s\n", k, g->infile[k]);
	// 		k = -1;
	// 		i++;
	// 	}
	// 	i= 0;
	// 	printf("append value %d\n", g->append);
	// 	printf("heredoc value %d\n", g->nb_heredoc);
	// 	printf("error value : %d\n", g->error);
	// 	g = g->next;
	// 	i = 0;
	// }
	/*-------------------*/
}

int	parser(t_master *master)
{
	if (!master)
		return (1);
	if (check_is_expand(&master->token_list, &master->env_clone) == 1)
		return (printf("PROBLEME EXPAND\n"), 1);
	merge_token(&master->token_list);
	directory_check(&master->token_list);
	parse_cmd(&master, 0, 0);
	// make_heredoc(&master->token_list, &master->cmd_list);
	return (0);
}
