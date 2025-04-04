/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:03:14 by daavril           #+#    #+#             */
/*   Updated: 2025/04/05 01:03:01 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_path(t_clone *envp_clone)
{
	t_clone	*current;
	char	*path_envp;

	current = envp_clone;
	path_envp = NULL;
	while (current)
	{
		if (ft_strncmp(current->value, "PATH=", 5) == 0)
		{
			path_envp = current->value + 5;
		}
		current = current->next;
	}
	if (path_envp == NULL)
	{
		perror("PATH not found in environment");
		exit(EXIT_FAILURE);
	}
	return (path_envp);
}
