/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:31:32 by daavril           #+#    #+#             */
/*   Updated: 2025/04/07 13:25:05 by daavril          ###   ########.fr       */
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

void	is_access(t_token *current, char *value)
{
	struct stat	info;

	if (stat(value, &info) != 0)
	{
		current->dir = -1;
		current->prog = -1;
		return ;
	}
	if (S_ISDIR(info.st_mode))
		current->dir = 1;
	if (access(value, X_OK) == 0)
		current->prog = 1;
}

void	directory_check(t_token **token_list)
{
	t_token	*current;

	current = *token_list;
	while (current)
	{
		current->prog = 0;
		current->dir = 0;
		if (!current->value_2)
		{
			if (ft_strchr(current->value, '/'))
				is_access(current, current->value);
		}
		else
		{
			if (ft_strchr(current->value_2, '/'))
				is_access(current, current->value_2);
		}
		current = current->next;
	}
}
