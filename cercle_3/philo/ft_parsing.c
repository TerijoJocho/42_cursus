/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:39:16 by daavril           #+#    #+#             */
/*   Updated: 2024/12/10 16:58:47 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_integer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	if (ft_atoi(str) < 1 || ft_atoi(str) > 2147483647)
		return (1);
	return (0);
}

int	parsing(char *argv)
{
	if (is_integer(argv) == 1)
		return (1);
	return (0);
}
