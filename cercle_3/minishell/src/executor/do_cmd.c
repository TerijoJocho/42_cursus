/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:50:58 by daavril           #+#    #+#             */
/*   Updated: 2025/04/07 14:11:24 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	do_child(t_cmd *cmd, int prev_fd, char **env, t_master *master)
{
	if (cmd->prev && prev_fd != -1)
	{
		dup2(prev_fd, STDIN_FILENO);
		close(prev_fd);
	}
	if (check_redir(cmd) == 1)
		if (cmd->next != NULL)
			dup2(cmd->pfd[1], STDOUT_FILENO);
	close(cmd->pfd[0]);
	close(cmd->pfd[1]);
	if (cmd->builtins == 0)
		define_exec(cmd, env, master);
	else
		execute_builtins(master, cmd, 0);
	clean_exit(1, master, 0);
}

int	do_parent(int *prev_fd, t_cmd *cur_cmd, int pid, t_master *m)
{
	int	status;

	status = 0;
	if (*prev_fd != -1)
		close(*prev_fd);
	close(cur_cmd->pfd[1]);
	*prev_fd = cur_cmd->pfd[0];
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		m->exit_status = WEXITSTATUS(status);
	else
		m->exit_status = 1;
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGQUIT)
	{
		write(2, "Quit (core dumped)\n", 20);
		return (1);
	}
	else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
		return (1);
	return (0);
}

void	do_cmd_solo(t_master *master, t_cmd *cmd, char **env, int status)
{
	t_cmd	*cur_cmd;
	pid_t	pid;

	cur_cmd = cmd;
	pid = fork();
	if (pid == 0 && check_cmd(master, cur_cmd, -1) == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		check_redir(cur_cmd);
		if (cmd->builtins == 0)
			define_exec(cmd, env, master);
		else
			execute_builtins(master, cmd, 0);
		clean_exit(0, master, 0);
	}
	else if (pid > 0)
	{
		(signal(SIGINT, SIG_IGN), waitpid(pid, &status, 0));
		if (WIFEXITED(status))
			master->exit_status = WEXITSTATUS(status);
		else
			master->exit_status = 1;
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGQUIT)
			write(2, "Quit (core dumped)\n", 20);
	}
}

void	do_cmd(t_master *m, t_cmd *cmd, char **env, int prev_fd)
{
	t_cmd	*cur_cmd;
	pid_t	pid;

	cur_cmd = cmd;
	while (cur_cmd)
	{
		pipe(cur_cmd->pfd);
		pid = fork();
		if (pid == 0 && check_cmd(m, cur_cmd, prev_fd) == 0)
			(signal(SIGQUIT, SIG_DFL), do_child(cur_cmd, prev_fd, env, m));
		else if (pid > 0)
		{
			if (do_parent(&prev_fd, cur_cmd, pid, m) == 1)
				break ;
			cur_cmd = cur_cmd->next;
		}
	}
	while (cur_cmd != NULL)
	{
		check_if_child(pid, 0, m);
		cur_cmd = cur_cmd->next;
	}
	if (prev_fd != -1)
		close(prev_fd);
}
