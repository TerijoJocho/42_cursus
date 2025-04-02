/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:57:01 by daavril           #+#    #+#             */
/*   Updated: 2025/04/02 16:20:26 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

int	check_in(t_cmd *cmd)
{
	int	fd;
	int	i;

	i = 0;
	if (!cmd->infile || !cmd->infile[0])
		return (1);
	while (cmd->infile[i])
		i++;
	if (i > 0)
		i--;
	if (cmd->infile[i])
	{
		fd = open(cmd->infile[i], O_RDONLY);
		if (fd == -1)
		{
			perror("open infile in exec");
			cmd->error = 1;
			return (-1);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	return (0);
}

int	check_out(t_cmd *cmd)
{
	int	fd;
	int	i;

	i = 0;
	if (!cmd->outfile || !cmd->outfile[0])
		return (1);
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
			return ((printf("open outfile in exec\n"), cmd->error = 1), -1);
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	return (0);
}

int	checkhere_doc(t_cmd *cmd)
{
	int	i;
	int	fd;

	i = 0;
	if (!cmd->link || !cmd->link[0])
		return (1);
	while (cmd->link[i])
		i++;
	if (i > 0)
		i--;
	if (cmd->link[i])
	{
		fd = open(cmd->link[i], O_RDONLY);
		if (fd == -1)
		{
			perror("open heredoc in exec");
			cmd->error = 1;
			return (-1);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
		unlink(cmd->link[i]);
	}
	return (0);
}

int	check_redir(t_cmd *cmd)
{
	int	res_in;
	int	res_out;
	int	res_here;

	res_in = 1;
	res_out = 1;
	res_here = 1;
	if (!cmd || cmd->error == 1)
		return (-1);
	if (cmd->outfile)
		res_out = check_out(cmd);
	if (cmd->nb_heredoc > 0)
		res_here = checkhere_doc(cmd);
	if (cmd->infile)
		res_in = check_in(cmd);
	if (res_out == -1 || res_here == -1 || res_in == -1)
		return (-1);
	if (res_out == 0 || res_here == 0 || res_in == 0)
		return (0);
	return (1);
}
