/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:40:08 by daavril           #+#    #+#             */
/*   Updated: 2024/10/28 19:30:37 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	sig_received;

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;

	(void)info;
	(void)context;
	sig_received = 1;
	if (signum == SIGUSR2)
		i++;
	else if (signum == SIGUSR1)
		ft_printf("Number of bytes received : %d\n", i / 8);
}

int	char_to_binary(char c, int pid)
{
	int	i;
	int	bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		i = 0;
		if ((c >> bit_index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (sig_received == 0)
		{
			if (i == 50)
			{
				ft_printf("No signal received.\nExit.\n");
				exit(1);
			}
			i++;
			usleep(100);
		}
		sig_received = 0;
		bit_index--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	__pid_t				pid;
	struct sigaction	sa;
	int					i;

	if (argc != 3)
	{
		ft_printf("You must write two arguments,");
		ft_printf("firts the pid then your message.\n");
	}
	pid = ft_atoi(argv[1]);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Signal error. \n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Signal error.\n");
	i = 0;
	while (argv[2][i])
		char_to_binary(argv[2][i++], pid);
	char_to_binary('\0', pid);
	return (0);
}
