/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:36:10 by daavril           #+#    #+#             */
/*   Updated: 2025/03/26 16:03:58 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**clone_tab_env(t_clone *env)
{
	char	**tab;
	t_clone	*cur;
	int		i;
	int		size;

	if (!env)
		return (NULL);
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
		ft_echo(cur_cmd, 0, master);
	else if (cur_cmd->builtins == EXPORT)
		ft_export(master, cur_cmd);
	else if (cur_cmd->builtins == EXIT)
		ft_exit(master, cur_cmd);
	else if (cur_cmd->builtins == UNSET)
		ft_unset(master, cur_cmd);
	else if (cur_cmd->builtins == ENV)
		ft_env(env, master);
	else if (cur_cmd->builtins == PWD)
		ft_pwd();
	else if (cur_cmd->builtins == CD)
		ft_cd(master, cur_cmd);
}

void	do_cmd_first(t_master *master, t_cmd *cmd, char **env)
{
	t_cmd	*cur_cmd;
	pid_t	pid;
	int		status;

	cur_cmd = cmd;
	if (cur_cmd->error == 1)
		return ; // gerer l'erreur
	pid = fork();
	if (pid == 0)
	{
		if (cur_cmd->builtins == 0)
		{
			if (execve(cur_cmd->path, cur_cmd->args, env) == -1)
			{
				perror("execve");
				clean_exit(127, master, 0) ;//exi(127)??
			}
		}
		else
			execute_builtins(master, cur_cmd, env); //ici aussi, recuperer un int flag pour savoir si la cmd a reussi
		clean_exit(1, master, 0) ;//faire les builltins hors fork
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			master->exit_status = WEXITSTATUS(status);
		else
			master->exit_status = 1;
	}
	else
		perror("fork");
}

int	executor(t_master *master)
{
	t_cmd	*cur;

	// pid_t	pid;
	// char	buf;
	// int	flag;
	// flag = 0;
	cur = master->cmd_list;
	master->env = clone_tab_env(master->env_clone);
	while (cur)
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
		// if (!cur->next)
		// 	do_cmd_solo(master, cur, master->env); //pour avoir le $?
		// else
			do_cmd_first(master, cur, master->env);
		cur = cur->next;
	}
	return (0);
}
