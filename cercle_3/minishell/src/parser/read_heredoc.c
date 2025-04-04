/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:58:07 by abastian          #+#    #+#             */
/*   Updated: 2025/04/05 00:58:38 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	noquote(t_cmd *node, t_master *m, char *lim)
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
	while (cur2 && ft_strncmp(cur2->value, lim, ft_strlen(cur2->value)) != 0)
		cur2 = cur2->next;
	if (cur2 && (cur2->quote_flag == 1 || cur2->double_quote == 1))
		return (1);
	return (0);
}

void	pre_expand(int fd, char *input, t_master *m)
{
	char	*exp;

	exp = NULL;
	exp = expand_heredoc(&m->env_clone, input, 0);
	if (!exp)
		return ;
	write_it(fd, exp);
	free(exp);
	exp = NULL;
}

void	heredoc_loop(int fd, char *lim, t_cmd *cur, t_master *m)
{
	char	*input;

	signal(SIGINT, handle_signal_heredoc);
	while (1)
	{
		input = readline("> ");
		if (g_signal == 1)
			(free(input), get_exit(m, fd));
		if (!input)
		{
			printf("\n");
			break ;
		}
		if (ft_strncmp(input, lim, ft_strlen(lim)) == 0
			&& ft_strlen(input) == ft_strlen(lim))
		{
			free(input);
			break ;
		}
		if (ft_strchr(input, '$') && noquote(cur, m, lim) == 0)
			pre_expand(fd, input, m);
		else
			write_it(fd, input);
		free(input);
	}
}

void	read_heredoc_next(t_cmd *cur, t_master *m, char **h, int i)
{
	int		fd;
	pid_t	pid;

	while (h[i])
	{
		fd = open(cur->link[i], O_WRONLY | O_TRUNC);
		if (fd == -1)
		{
			cur->error = 1;
			return ;
		}
		(signal(SIGINT, SIG_IGN), pid = fork());
		if (pid == 0)
			(heredoc_loop(fd, h[i], cur, m), close(fd), clean_exit(0, m, 0));
		else if (waitloop(pid, 0, fd, cur) == 1)
			return ;
		(set_signal(), close(fd), i++);
	}
}

void	read_heredoc(t_cmd **cmd, t_master *m)
{
	t_cmd	*cur;

	cur = *cmd;
	while (cur)
	{
		if (cur->nb_heredoc > 0)
		{
			if (cur->prev && cur->prev->error == 1)
				break ;
			read_heredoc_next(cur, m, cur->heredoc, 0);
		}
		cur = cur->next;
	}
}
