/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:36:10 by daavril           #+#    #+#             */
/*   Updated: 2025/03/28 14:36:57 by daavril          ###   ########.fr       */
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
		ft_exit(master, cur_cmd, f); // ca depend du moment pour le flag
	else if (cur_cmd->builtins == UNSET)
		ft_unset(master, cur_cmd);
	else if (cur_cmd->builtins == ENV)
		ft_env(master);
	else if (cur_cmd->builtins == PWD)
		ft_pwd();
	else if (cur_cmd->builtins == CD)
		ft_cd(master, cur_cmd);
}

void	check_in(t_cmd *cmd)
{
	int	fd;
	int	i;
	printf("prout\n");

	i = 0;
	printf("cmd->infile dans exec: %p\n", cmd->infile);
	while (cmd->infile[i])
		i++;
	printf("i in exec: %d\n", i);
	if ( i > 0)
		i--;
	if (cmd->infile[i])
	{
		printf("infile: %s\n", cmd->infile[i]);
		fd = open(cmd->infile[i], O_RDONLY);
		printf("fd= %d\n", fd);
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

void	checkhere_doc(t_cmd *cmd)
{
	int	fd;
	int	i;

	i = 0;
	if (!cmd->link || !cmd->link[0])
		return ;
	while (cmd->link[i])
		i++;
	i--;
	if (cmd->link[i])
	{
		printf("link:%s\n", cmd->link[i]);
		fd = open(cmd->link[i], O_RDONLY);
		if (fd == -1)
		{
			perror("open heredoc in exec");
			cmd->error = 1;
			return ;
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}

int	check_redir(t_cmd *cmd_list)
{
	t_cmd	*cmd;

	cmd = cmd_list;
	if (!cmd)
		return (1);
	while (cmd)
	{
		if (cmd->error == 1)
			break ;
		if (cmd->infile)
			check_in(cmd);
		else if (cmd->outfile)
			check_out(cmd);
		else if (cmd->nb_heredoc > 0)
			checkhere_doc(cmd);
		cmd = cmd->next;
	}
	if (cmd && cmd->error == 1)
	{
		printf("error check_redir\n");
		return (1);
	}
	return (0);
}

/*si on a plusieurs cmd*/
void	do_cmd_first(t_master *master, t_cmd *cmd, char **env)
{
	t_cmd	*cur_cmd;
	pid_t	pid;
	int		status;
	int	saved_stdout;

	cur_cmd = cmd;
	if (cur_cmd->error == 1)
		return ; // gerer l'erreur
	saved_stdout = dup(STDOUT_FILENO);
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
		dup2(saved_stdout, STDOUT_FILENO);
		close(saved_stdout);
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
	close(saved_stdout);
}

int	executor(t_master *master)
{
	t_cmd	*cur;

	// pid_t	pid;
	// char	buf;
	// int	flag;
	// flag = 0;
	cur = master->cmd_list;
	master->env = clone_tab_env(master->env_clone, 0);
	while (cur)
	{
		if (!cur->next && !cur->prev && cur->builtins > 0)
			// execute_builtins(master, cur, 1);
			do_cmd_first(master, cur, master->env);
		// else if (cur->next && flag == 1)
		// {
		// 	do_cmd_middle();
		// 	flag = 1;
		// }
		// else if (!cur->next)
		// 	do_cmd_last(cur);
		// if (!cur->next)
		// 	do_cmd_solo(master, cur, master->env); //pour avoir le $?
		else
			do_cmd_first(master, cur, master->env);
		cur = cur->next;
	}
	return (0);
}
