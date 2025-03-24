/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:03:14 by daavril           #+#    #+#             */
/*   Updated: 2025/03/03 09:04:20 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

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

int	is_intern(char *value, t_master **master)
{
	char	**path_dir;
	char	*full_path;
	int		i;

	path_dir = ft_split(get_path((*master)->env_clone), ':');
	i = 0;
	while (path_dir[i])
	{
		full_path = ft_strjoin(path_dir[i], "/");
		full_path = ft_strjoin(full_path, value);
		if (access(full_path, X_OK) == 0)
		{
			printf("path[%d] = %s\n",i , path_dir[i]);
			free(full_path);
			return (1);
		}
		free(full_path);
		i++;
	}
	return (0);
}
