/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:58:07 by abastian          #+#    #+#             */
/*   Updated: 2025/03/28 12:36:35 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

void	heredoc_loop(int fd, char *lim)
{
	char	*input;

	while (1)
	{
		input = readline("> ");
		if (!input || ft_strncmp(input, lim, ft_strlen(lim)) == 0)
		{
			free(input);
			break ;
		}
		// if (ft_strchr(input, '$'))
		// 	input =
		write(fd, input, ft_strlen(input));
		write(fd, "\n", 1);
		free(input);
	}
}

void	read_heredoc_next(char **her, char **link, int *error)
{
	int		fd;
	int	i;

	i = 0;
	while (her[i])
	{
		fd = open(link[i], O_WRONLY | O_TRUNC);
		if (fd == -1)
		{
			printf("Error with open in heredoc\n");
			(*error) = 1;
			return ;
		}
		heredoc_loop(fd, her[i]);
		close(fd);
		i++;
	}
}

void	read_heredoc(t_cmd **cmd)
{
	t_cmd	*cur;

	cur = *cmd;
	while (cur)
	{
		if (cur->nb_heredoc > 0)
			read_heredoc_next(cur->heredoc, cur->link, &cur->error);
		cur = cur->next;
	}
}
