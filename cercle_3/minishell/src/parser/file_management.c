/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:37:46 by abastian          #+#    #+#             */
/*   Updated: 2025/04/05 00:54:20 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	infile_check(char **infile, int *error)
{
	int	i;

	i = 0;
	if (!infile || !infile[0])
		return (1);
	while (infile[i] && infile[i] != NULL)
	{
		if (access(infile[i], F_OK) == -1)
		{
			(*error) = 1;
			return (0);
		}
		if (access(infile[i], R_OK) == -1)
		{
			(*error) = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

int	create_file(char *name, int append, int *error)
{
	int	fd;

	if (append == 0)
	{
		fd = open(name, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd == -1)
			return ((*error) = 1, 0);
		close(fd);
	}
	else
	{
		fd = open(name, O_CREAT | O_RDWR | O_APPEND, 0644);
		if (fd == -1)
			return ((*error) = 1, 0);
		close(fd);
	}
	return (1);
}

int	outfile_check(char **outfile, int *error, int *append)
{
	int	i;

	i = 0;
	if (!outfile || !outfile[0])
		return (1);
	while (outfile[i])
	{
		if (access(outfile[i], F_OK) == -1)
		{
			if (create_file(outfile[i], append[i], error) == 0)
				return (0);
		}
		else
		{
			if (access(outfile[i], W_OK) == -1)
				return ((*error) = 1, 0);
			if (append[i] == 0)
			{
				if (create_file(outfile[i], append[i], error) == 0)
					return (0);
			}
		}
		i++;
	}
	return (1);
}

void	file_management(t_cmd **cmd)
{
	t_cmd	*cur;

	cur = *cmd;
	while (cur)
	{
		if (infile_check(cur->infile, &cur->error) == 0)
			printf("Error with an infile non existent or non readable\n");
		if (outfile_check(cur->outfile, &cur->error, cur->append) == 0)
			printf("Outfile error\n");
		if (make_heredoc(cur->heredoc, &cur->error, cur->link) == 0)
			printf("Error with heredoc files creation\n");
		cur = cur->next;
	}
}
