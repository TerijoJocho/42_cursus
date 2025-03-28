/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:40:23 by daavril           #+#    #+#             */
/*   Updated: 2025/03/28 16:52:53 by abastian         ###   ########.fr       */
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

int	is_append(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (!cmd->append || !cmd->append[0])
		return (1);
	while (cmd->append[i])
	{
		if (cmd->append[i] == 1)
			return (1);
		i++;
	}
	return (0);
}

void	check_in(t_cmd *cmd)
{
	int	fd;
	int	i;

	i = 0;
	while (cmd->infile[i])
		i++;
	if ( i > 0)
		i--;
	if (cmd->infile[i])
	{
		fd = open(cmd->infile[i], O_RDONLY);
		if (fd == -1)
		{
			perror("open infile in exec");
			cmd->error = 1;
			return ;
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}

void	check_out(t_cmd *cmd)
{
	int	fd;
	int	i;

	i = 0;
	if (!cmd->outfile || !cmd->outfile[0])
		return ;
	while (cmd->outfile[i])
		i++;
	if (i > 0)
		i--;
	if (cmd->outfile[i])
	{
		if (is_append(cmd) == 1)
			fd = open(cmd->outfile[i], O_WRONLY | O_APPEND);
		else
			fd = open(cmd->outfile[i], O_WRONLY | O_TRUNC);
		if (fd == -1)
		{
			perror("open outfile in exec"), cmd->error = 1;
			return ;
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}

void	check_redir(t_cmd *cmd)
{
	if (!(cmd))
		return ;
	if (cmd->error == 1)
		return ;
	if (cmd->infile)
		check_in(cmd);
	if (cmd->outfile)
		check_out(cmd);
	// else if (cmd->nb_heredoc > 0)
	// 	checkhere_doc(cmd);
	cmd = cmd->next;
	if (cmd && cmd->error == 1)
	{
		printf("error check_redir\n");
		return ;
	}
	return ;
}

void	do_cmd_first(t_master *master, t_cmd *cmd, char **env)
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

	cur = master->cmd_list;
	master->env = clone_tab_env(master->env_clone, 0);
	while (cur)
	{
		if (!cur->next && !cur->prev && (cur->builtins == 3
			|| (cur->builtins == 5 && cur->args[1]) || cur->builtins == 6 || cur->builtins == 8))
			execute_builtins(master, cur, 1);
		else
			do_cmd_first(master, cur, master->env);
		cur = cur->next;
	}
	return (0);
}
