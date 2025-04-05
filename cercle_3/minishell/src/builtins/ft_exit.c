/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:52:31 by abastian          #+#    #+#             */
/*   Updated: 2025/04/05 04:11:26 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_value(char *arg)
{
	int	keep;

	keep = ft_atoi(arg);
	if (keep < 0)
		keep *= -1;
	if (keep > 255)
		keep = (keep % 256);
	return (keep);
}

void	clean_exit(int value, t_master *master, int flag)
{
	free_all(master);
	clean_env(&master->env_clone);
	clean_env(&master->export_list);
	if (master)
	{
		free(master);
		master = NULL;
	}
	if (flag == 1)
		printf("exit\n");
	exit(value);
}

int	is_sign_digit(int c)
{
	// if (c == '+' || c == '-')
	// 	return (2);//ICI
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_exit(t_master *master, t_cmd *cur_cmd, int flag)
{
	int	i;
	int	keep;

	keep = 0;
	i = 0;
	if (!cur_cmd->args[1])
		clean_exit(0, master, flag);
	if (cur_cmd->args[2])
	{
		printf("exit\n");
		printf("exit: too many arguments\n");
		return ;
	}
	while (cur_cmd->args[1][i])
	{
		if (is_sign_digit(cur_cmd->args[1][i]) == 0)
		{
			printf("exit: %s: numeric argument required\n", cur_cmd->args[1]);
			clean_exit(2, master, flag);
		}
		i++;
	}
	keep = get_value(cur_cmd->args[1]);
	clean_exit(keep, master, flag);
}
