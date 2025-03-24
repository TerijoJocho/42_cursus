/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:36:10 by daavril           #+#    #+#             */
/*   Updated: 2025/03/24 17:00:53 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**clone_tab_env(t_clone *env)
{
	char	**tab;
	t_clone	*cur;
	int		i;
	int		size;

	cur = env;
	size = 0;
	while (cur)
	{
		cur = cur->next;
		size++;
	}
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	cur = env;
	while (cur)
	{
		tab[i] = ft_strdup(cur->value);
		cur = cur->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	execute_builtins(t_master *master, t_cmd *cur_cmd, char **env)
{
	if (cur_cmd->builtins == ECHO)
		ft_echo(cur_cmd, 0);
	else if (cur_cmd->builtins == EXPORT)
		ft_export(master, cur_cmd);
	// else if (cur_cmd->builtins == EXIT)
	// 	ft_exit();
	else if (cur_cmd->builtins == UNSET)
		ft_unset(master, cur_cmd);
	else if (cur_cmd->builtins == ENV)
		ft_env(env);
	else if (cur_cmd->builtins == PWD)
		ft_pwd();
	else if (cur_cmd->builtins == CD)
		ft_cd(master, cur_cmd);
}

void	do_cmd_last(t_master *master, t_cmd *cmd, char **env)
{
	t_cmd	*cur_cmd;
	pid_t	pid;

	cur_cmd = cmd;
	if (cur_cmd->error == 1)
		return ; //gerer l'erreur
	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
	{
		if (cur_cmd->builtins == 0)
		{
			if (execve(cur_cmd->path, cur_cmd->args, env) == -1)
			{
				printf("Error execve\n");
				exit(1) ;
			}
		}
		else
			execute_builtins(master, cur_cmd, env);
	}
	else
		waitpid(pid, NULL, 0);
}


int	executor(t_master *master)
{
	// pid_t	pid;
	// char	buf;
	t_cmd	*cur;
	// int	flag;

	// flag = 0;
	cur = master->cmd_list;
	master->env = clone_tab_env(master->env_clone);
	while(cur)
	{
		// if (cur->next && flag == 0)
		// 	do_cmd_first(cur);
		// else if (cur->next && flag == 1)
		// {
		// 	do_cmd_middle();
		// 	flag = 1;
		// }
		// else if (!cur->next)
		// 	do_cmd_last(cur);
		do_cmd_last(master, cur, master->env);
		cur = cur->next;
	}
	return (0);
}
