/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:27:04 by abastian          #+#    #+#             */
/*   Updated: 2025/03/24 15:03:24 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	option_check(char *arg)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (1);
		i++;
	}
	if (i <= 1)
		return (1);
	return (0);
}

void	ft_echo(t_cmd *cur_cmd, int i)
{
	int	newline;

	newline = 1;
	if (!cur_cmd->args[1])
	{
		printf("\n");
		return ;
	}
	while (cur_cmd->args[i++] && cur_cmd->args[i][0] == '-'
		&& option_check(cur_cmd->args[i]) == 0)
	{
		if (cur_cmd->args[i][0] == '-' && newline == 1)
			newline = option_check(cur_cmd->args[i]);
	}
	while (cur_cmd->args[i])
	{
		printf("%s", cur_cmd->args[i]);
		if (cur_cmd->args[i + 1])
			printf(" ");
		i++;
	}
	if (newline == 1)
		printf("\n");
}
