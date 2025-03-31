/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:40:23 by daavril           #+#    #+#             */
/*   Updated: 2025/03/31 16:34:48 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**clone_tab_env(t_clone *env, int size)
{
	char	**tab;
	t_clone	*cur;
	int		i;

	if (!env)
		return (NULL);
	cur = env;
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

void	execute_builtins(t_master *master, t_cmd *cur_cmd, int f)
{
	if (cur_cmd->builtins == ECHO)
		ft_echo(cur_cmd, 0, master);
	else if (cur_cmd->builtins == EXPORT)
		ft_export(master, cur_cmd);
	else if (cur_cmd->builtins == EXIT)
		ft_exit(master, cur_cmd, f);
	else if (cur_cmd->builtins == UNSET)
		ft_unset(master, cur_cmd);
	else if (cur_cmd->builtins == ENV)
		ft_env(master);
	else if (cur_cmd->builtins == PWD)
		ft_pwd();
	else if (cur_cmd->builtins == CD)
		ft_cd(master, cur_cmd);
}

void	do_cmd_solo(t_master *master, t_cmd *cmd, char **env)
{
	t_cmd	*cur_cmd;
	pid_t	pid;
	int		status;

	cur_cmd = cmd;
	// gerer erreur
	pid = fork();
	if (pid == 0)
	{
		check_redir(cur_cmd);
		if (execve(cur_cmd->path, cur_cmd->args, env) == -1)
		{
			perror("execve");
			clean_exit(127, master, 0);
		}
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

void	do_cmd(t_master *master, t_cmd *cmd, char **env)
{
	t_cmd	*cur_cmd;
	pid_t	pid;
	int		status;
	int		prev_fd;

	cur_cmd = cmd;
	// gerer erreur
	prev_fd = -1;
	while (cur_cmd)
	{
		pipe(cur_cmd->pfd);
		pid = fork();
		if (pid == 0)
		{
			if (cur_cmd->prev && prev_fd != -1)
			{
				dup2(prev_fd, STDIN_FILENO);
				close(prev_fd);
			}
			if (check_redir(cur_cmd) == 1)
				if (cur_cmd->next != NULL)
				{
					dup2(cur_cmd->pfd[1], STDOUT_FILENO);
				}
			close(cur_cmd->pfd[0]);
			close(cur_cmd->pfd[1]);
			if (cur_cmd->builtins == 0)
			{
				if (execve(cur_cmd->path, cur_cmd->args, env) == -1)
				{
					perror("execve");
					clean_exit(127, master, 0);
				}
			}
			else
				execute_builtins(master, cur_cmd, 0);
			clean_exit(1, master, 0);
		}
		else if (pid > 0)
		{
			close(cur_cmd->pfd[1]);
			prev_fd = cur_cmd->pfd[0];
			waitpid(pid, &status, 0);
			cur_cmd = cur_cmd->next;
		}
	}
	while (cur_cmd != NULL)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
				master->exit_status = WEXITSTATUS(status);
		else
			master->exit_status = 1;
		cur_cmd = cur_cmd->next;
	}
}

int	executor(t_master *master)
{
	t_cmd	*cur;

	cur = master->cmd_list;
	// check cmd, si c'est une commande qui existe pas alors on fait pas execve
	master->env = clone_tab_env(master->env_clone, 0);
	if (!cur->next && !cur->prev && (cur->builtins == 3 || (cur->builtins == 5
				&& cur->args[1]) || cur->builtins == 6 || cur->builtins == 8))
		execute_builtins(master, cur, 1);
	else if (!cur->next && !cur->prev)
		do_cmd_solo(master, cur, master->env);
	else if (cur->next && !cur->prev)
		do_cmd(master, cur, master->env);
	return (0);
}
