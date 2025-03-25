/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:19:46 by daavril           #+#    #+#             */
/*   Updated: 2025/03/25 16:03:26 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <errno.h>
#include <string.h>

char	*get_pwd(t_master *master, char *var, int i)
{
	t_clone		*clone_env;
	char		*path;

	clone_env = master->env_clone;
	if (clone_env == NULL)
		return (NULL);
	path = NULL;
	while (clone_env)
	{
		if (ft_strncmp(clone_env->value, var, i) == 0)
		{
			path = ft_substr(clone_env->value, i, ft_strlen(clone_env->value + i));
			break ;
		}
		clone_env = clone_env->next;
	}
	return (path);
}

void	update_env(t_master *master, char *var, char *new_value)
{
	t_clone *clone_env;

	clone_env = master->env_clone;
	while (clone_env)
	{
		if (ft_strncmp(clone_env->value, var, ft_strlen(var)) == 0)
		{
			free(clone_env->value);
			clone_env->value = ft_strjoin(var, new_value);
			return ;
		}
		clone_env = clone_env->next;
	}
}

/*change le repertoire actuel encelui qu'on envoit*/
int		ft_cd(t_master *master, t_cmd *cmd)
{
	char    *path;
	char	*oldpwd;
	char	*newpwd;

	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
		return (printf("cd: can not get current directory: %s\n", strerror(errno)), 1);
	if (cmd->args[1] == NULL)
	{
		path = get_pwd(master, "HOME=", 5);
		if (path == NULL)
			return (printf("cd: HOME not set\n"), free(oldpwd), 1);
	}
	else if (cmd->args[2])
		return(printf("cd: too many arguments\n"), free(oldpwd), 1);
	else if (ft_strncmp(cmd->args[1], "-", 1) == 0)
	{
		path = get_pwd(master, "OLDPWD=", 7);
		if (path == NULL)
			return (printf("cd: OLDPWD not set\n"), free(oldpwd), 1);
		printf("%s\n", path);
	}
	else
		path = cmd->args[1];
	if (access(path, F_OK) == -1)
		return (printf("cd: no such file or directory: %s\n", path), free(oldpwd), 1);
	if (access(path, X_OK) == -1)
		return (printf("cd: permission denied: %s\n", path), free(oldpwd), 1);
	if (chdir(path) == -1)
		return (printf("cd: %s: %s\n", path, strerror(errno)), free(oldpwd), 1);
	update_env(master, "OLDPWD=", oldpwd);
	newpwd = getcwd(NULL, 0);
	if (newpwd)
		update_env(master, "PWD=", newpwd);
	free(oldpwd);
	free(newpwd);
	return (0);
}
