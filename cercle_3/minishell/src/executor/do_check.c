/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:52:33 by daavril           #+#    #+#             */
/*   Updated: 2025/04/07 16:38:43 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_dir_exec(t_cmd *node, t_master *m)
{
	t_cmd	*cur;
	t_token	*cur2;
	int		i;
	int		k;

	i = 0;
	k = 0;
	cur = m->cmd_list;
	cur2 = m->token_list;
	while (cur && cur != node)
	{
		i++;
		cur = cur->next;
	}
	while (cur2 && k != i)
	{
		if (cur2->real == PIPE)
			k++;
		cur2 = cur2->next;
	}
	if (cur2 && cur2->dir == 1)
		return (1);
	if (cur2 && cur2->prog == 1)
		return (2);
	return (0);
}

void	define_exec(t_cmd *cmd, char **env, t_master *master)
{
	int	kind;

	kind = is_dir_exec(cmd, master);
	if (kind == 2)
	{
		if (execve(cmd->args[0], cmd->args, env) == -1)
		{
			perror("execve executable");
			clean_exit(127, master, 0);
		}
	}
	if (execve(cmd->path, cmd->args, env) == -1)
	{
		perror("execve");
		clean_exit(127, master, 0);
	}
}

void	clean_pipes(t_master *master, t_cmd *cmd, int value, int pfd)
{
	close(cmd->pfd[0]);
	close(cmd->pfd[1]);
	if (pfd != -1)
		close(pfd);
	master->exit_status = value;
	clean_exit(value, master, 0);
}

int	check_cmd(t_master *master, t_cmd *cmd, int pfd)
{
	int	kind;

	kind = is_dir_exec(cmd, master);
	if (cmd->args[0][0] == '\0')
		return (clean_pipes(master, cmd, 0, pfd), 1);
	if (cmd->error == 1)
		return (clean_pipes(master, cmd, 127, pfd), 1);
	if (cmd->builtins > 0)
		return (0);
	if (kind == 1)
		return (printf("%s: Is a directory\n", cmd->args[0]),
			clean_pipes(master, cmd, 126, pfd), 1);
	if (kind == 2)
		return (0);
	else if (cmd->path == NULL)
		return (printf("%s: command not found\n", cmd->args[0]),
			clean_pipes(master, cmd, 127, pfd), 1);
	else if (access(cmd->path, X_OK) != 0)
		return (printf("%s: no such file or directory\n", cmd->args[0]),
			clean_pipes(master, cmd, 126, pfd), 1);
	return (0);
}

void	check_if_child(int pid, int status, t_master *master)
{
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		master->exit_status = WEXITSTATUS(status);
	else
		master->exit_status = 1;
}
