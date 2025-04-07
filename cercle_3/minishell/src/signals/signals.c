/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:46:59 by daavril           #+#    #+#             */
/*   Updated: 2025/04/07 16:19:56 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_signal_minishell(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handle_signal_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		g_signal = 1;
		printf("\n");
		close(0);
	}
}

void	handle_signal_exec(int sig)
{
	if (sig == SIGQUIT)
		signal(SIGQUIT, SIG_DFL);
}

void	get_exit(t_master *master, int fd)
{
	(void)master;
	if (g_signal == 1)
	{
		g_signal = 0;
		if (fd != -1)
			close(fd);
		clean_heredoc(master);
		clean_exit(2, master, 0);
	}
}

void	set_signal(void)
{
	g_signal = 0;
	signal(SIGINT, handle_signal_minishell);
	signal(SIGQUIT, SIG_IGN);
}
