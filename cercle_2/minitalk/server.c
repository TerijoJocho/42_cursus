/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:13:21 by daavril           #+#    #+#             */
/*   Updated: 2024/11/05 15:17:03 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	binary_to_char(int signum, char *binary)
{
	if (signum == SIGUSR1)
		*binary = (*binary << 1) | 1;
	else if (signum == SIGUSR2)
		*binary = *binary << 1;
}

int	handle_lst(t_list **lst, char c)
{
	char	*char_ptr;
	t_list	*new_node;

	char_ptr = malloc(sizeof(char));
	if (!char_ptr)
		return (free_lst(lst), ft_printf("Malloc error.\n"), 0);
	*char_ptr = c;
	new_node = ft_lstnew(char_ptr);
	if (!new_node)
	{
		free(char_ptr);
		return (free_lst(lst), ft_printf("Malloc error.\n"), 0);
	}
	if (*lst == NULL)
		*lst = new_node;
	else
		ft_lstadd_back(lst, new_node);
	return (1);
}

void	display(t_list *string)
{
	while (string)
	{
		ft_printf("%c", *(char *)string->content);
		string = string->next;
	}
	write(1, "\n", 1);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int		pid;
	static int		i;
	static char		c;
	static t_list	*string;

	(void)context;
	if (pid == 0)
		pid = info->si_pid;
	binary_to_char(signum, &c);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(pid, SIGUSR1);
			pid = 0;
			display(string);
			free_lst(&string);
			return ;
		}
		if (!(handle_lst(&string, c)))
			return ;
		c = 0;
	}
	kill(pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server pid :%d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Signal error. \n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Signal error.\n");
	while (1)
		pause();
	return (0);
}
