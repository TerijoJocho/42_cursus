/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:19:46 by daavril           #+#    #+#             */
/*   Updated: 2025/04/05 03:45:12 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <errno.h>
#include <string.h>

char	*get_pwd(t_master *master, char *var, int i)
{
	t_clone	*clone_env;
	char	*p;

	clone_env = master->env_clone;
	if (clone_env == NULL)
		return (NULL);
	p = NULL;
	while (clone_env)
	{
		if (ft_strncmp(clone_env->value, var, i) == 0)
		{
			p = ft_substr(clone_env->value, i, ft_strlen(clone_env->value
						+ i));
			break ;
		}
		clone_env = clone_env->next;
	}
	return (p);
}

void	update_env(t_master *master, char *var, char *new_value)
{
	t_clone	*clone_env;

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

void	f(char *path, char *oldpwd, char *newpwd)
{
	if (oldpwd != NULL)
		free(oldpwd);
	oldpwd = NULL;
	if (newpwd != NULL)
		free(newpwd);
	newpwd = NULL;
	if (path != NULL)
		free(path);
	path = NULL;
}

int	check_cd(t_master *master, char *o, char **p, t_cmd *cmd)
{
	if (!o)
		return (printf("cd: can not get current directory: %s\n",
				strerror(errno)), 1);
	if (cmd->args[1] == NULL)
	{
		(*p) = get_pwd(master, "HOME=", 5);
		if ((*p) == NULL)
			return (printf("cd: HOME not set\n"), 1);
	}
	else if (cmd->args[2])
		return (printf("cd: too many arguments\n"), 1);
	else if (ft_strncmp(cmd->args[1], "-", 1) == 0)
	{
		(*p) = get_pwd(master, "OLDPWD=", 7);
		if ((*p) == NULL)
			return (printf("cd: OLDPWD not set\n"), 1);
		printf("%s\n", (*p));
	}
	else
		(*p) = ft_strdup(cmd->args[1]);
	return (0);
}

int	ft_cd(t_master *master, t_cmd *cmd)
{
	char	*p;
	char	*o;
	char	*n;

	o = getcwd(NULL, 0);
	p = NULL;
	n = NULL;
	check_cd(master, o, &p, cmd);
	if (!p)
		return (f(p, o, n), 1);
	if (access(p, F_OK) == -1)
		return (printf("cd: no such file or directory: %s\n", p),
			f(p, o, n), 1);
	if (access(p, X_OK) == -1)
		return (printf("cd: permission denied: %s\n", p), f(p, o, n), 1);
	if (chdir(p) == -1)
		return (printf("cd: %s: %s\n", p, strerror(errno)), f(p, o, n), 1);
	update_env(master, "OLDPWD=", o);
	n = getcwd(NULL, 0);
	if (n)
		update_env(master, "PWD=", n);
	f(p, o, n);
	return (0);
}
