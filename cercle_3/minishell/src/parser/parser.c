/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:40:34 by daavril           #+#    #+#             */
/*   Updated: 2025/03/26 16:04:40 by daavril          ###   ########.fr       */
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

// void	add_cmd(t_cmd *node, char *va, int *i, int flag, char	*path)
// {
// 	char	**split_path;
// 	char	*full_path;
// 	int		j;

// 	full_path = NULL;
// 	printf("VALEUR DE mii : %d\n", (*i));
// 	node->args[*i] = ft_strdup(va);
// 	if (flag == 1 || path == NULL)
// 	{
// 		(*i)++;
// 		return ;
// 	}
// 	split_path = ft_split(path, ':');
// 	j = 0;
// 	while (split_path[j])
// 	{
// 		path = ft_strjoin(split_path[j], "/");
// 		full_path = ft_strjoin(path, va);
// 		free(path);
// 		// printf("full_path value : %s\n", full_path);
// 		if (access(full_path, X_OK) == 0)
// 		{
// 			node->path = full_path;
// 			// printf("node->path value : %s\n", node->path);
// 			(*i)++;
// 			free_tab(split_path);
// 			return ;
// 		}
// 		free(full_path);
// 		full_path = NULL;
// 		j++;
// 	}
// 	free_tab(split_path);
// 	(*i)++;
// }

int	add_cmd2(char **split, char *fp, char *path, char *va, t_cmd *n)
{
	int	j;

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
	char	*full_path;

	full_path = NULL;
	node->args[*i] = ft_strdup(va);
	if (flag == 1 || path == NULL)
	{
		(*i)++;
		return ;
	}
	split_path = ft_split(path, ':');
	if (add_cmd2(split_path, full_path, path, va, node) == 1)
	{
		(*i)++;
		return ;
	}
	free_tab(split_path);
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

void	test(t_cmd **cmd)
{
	int		i;
	t_cmd	*cur;

	i = 0;
	cur = *cmd;
	while (cur)
	{
		i = 0;
		printf("nb_heredoc attendu : %d\n", cur->nb_heredoc);
		while (cur->link[i])
		{
			printf("link[%d] value : %s\n", i, cur->link[i]);
			unlink(cur->link[i]);
			i++;
		}
		cur = cur->next;
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
	parse_cmd(&master, 0, 0);
	file_management(&master->cmd_list);
	test(&master->cmd_list);
	return (0);
}
