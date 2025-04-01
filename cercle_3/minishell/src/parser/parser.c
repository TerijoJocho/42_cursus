/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:40:34 by daavril           #+#    #+#             */
/*   Updated: 2025/04/01 17:12:49 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_getenv(t_master **master)
{
	t_clone	*cur;
	char	*path;

	cur = (*master)->env_clone;
	while (cur)
	{
		if (ft_strncmp(cur->value, "PATH=", 5) == 0)
		{
			path = ft_substr(cur->value, 5, ft_strlen(cur->value));
			return (path);
		}
		cur = cur->next;
	}
	return (NULL);
}

int	add_cmd2(char **split, char *va, t_cmd *n)
{
	int	j;
	char	*path;
	char	*fp;


	fp = NULL;
	j = 0;
	while (split[j])
	{
		path = ft_strjoin(split[j], "/");
		fp = ft_strjoin(path, va);
		free(path);
		if (access(fp, X_OK) == 0)
		{
			n->path = fp;
			free_tab(split);
			return (1);
		}
		free(fp);
		fp = NULL;
		j++;
	}
	return (0);
}

void	add_cmd(t_cmd *node, char *va, int *i, int flag, char *path)
{
	char	**split_path;

	if (flag == 1)
	{
		free(path);
		return ;
	}
	node->args[*i] = ft_strdup(va);
	(*i)++;
	if (path == NULL)
		return ;
	split_path = ft_split(path, ':');
	free(path);
	if ((*i) == 1)
	{
		if (!split_path)
			return ;
		if (add_cmd2(split_path, va, node) == 1)
			return ;
		free_tab(split_path);
	}
	else
		free_tab(split_path);
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
			add_cmd(cmd_list, cur->value, &i, flag, ft_getenv(master));
		else if (cur->value_2 != NULL)
			add_cmd(cmd_list, cur->value_2, &i, flag, ft_getenv(master));
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
}

// void	test(t_cmd **cmd)
// {
// 	int		i;
// 	t_cmd	*cur;

// 	i = 0;
// 	cur = *cmd;
// 	while (cur)
// 	{
// 		i = 0;
// 		printf("nb_heredoc attendu : %d\n", cur->nb_heredoc);
// 		while (cur->link[i])
// 		{
// 			printf("link[%d] value : %s\n", i, cur->link[i]);
// 			unlink(cur->link[i]);
// 			i++;
// 		}
// 		cur = cur->next;
// 	}
// }

int	parser(t_master *master)
{
	if (!master)
		return (1);
	if (check_is_expand(&master->token_list, &master->env_clone) == 1)
		return (printf("PROBLEME EXPAND\n"), 1);
	merge_token(&master->token_list);
	directory_check(&master->token_list);
	parse_cmd(&master, 0, 0);
	file_management(&master->cmd_list);
	read_heredoc(&master->cmd_list, master);
	// test(&master->cmd_list);
	return (0);
}
