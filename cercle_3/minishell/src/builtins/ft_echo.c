/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:27:04 by abastian          #+#    #+#             */
/*   Updated: 2025/04/05 00:52:05 by daavril          ###   ########.fr       */
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

int	is_dollar(char *str, t_master *master)
{
	char	*status_str;
	int		x;

	status_str = ft_itoa(master->exit_status);
	x = ft_strncmp(str, "$?", 2);
	if (str && x == 0)
	{
		if (!status_str)
			return (1);
		free(status_str);
		return (0);
	}
	if (status_str)
		free(status_str);
	return (1);
}

void	ft_echo(t_cmd *cur_cmd, int i, t_master *master)
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
		if (is_dollar(cur_cmd->args[i], master) == 1)
			printf("%s", cur_cmd->args[i]);
		if (cur_cmd->args[i + 1])
			printf(" ");
		i++;
	}
	if (newline == 1)
		printf("\n");
}
