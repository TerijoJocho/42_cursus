/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:46:59 by daavril           #+#    #+#             */
/*   Updated: 2025/04/02 17:00:54 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

void	handle_signal_minishell(int sig)
{
	if (sig == SIGINT)
	{
		// clean ?
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
	}
	if (sig == SIGQUIT)
		printf("\b\b \b\b");
}

void	get_exit(t_master *master, int fd)
{
	if (g_signal == 1)
	{
		if (fd != -1)
			close(fd);
		clean_exit(0, master, 0);
	}
}

void	handle_signal_fork()
{

}

void	set_signal(void)
{
	g_signal = 0;
	signal(SIGINT, handle_signal_minishell);
	signal(SIGQUIT, SIG_IGN);
}

