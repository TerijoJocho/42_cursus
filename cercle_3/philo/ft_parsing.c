/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:39:16 by daavril           #+#    #+#             */
/*   Updated: 2024/11/18 10:40:26 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_integer(char *str)
{
	long long	res;

	res = 0;
	if (*str == '-' || *str == '+')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		res = res * 10 + (*str - '0');
		if (res >= 2147483648)
			return (0);
		str++;
	}
	return (1);
}

void	parsing(char *argv)
{
	if (!(is_integer(argv)))
		ft_error("One of the parameters is not an integer.\n");
}
