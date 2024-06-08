/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_undec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:42:59 by daavril           #+#    #+#             */
/*   Updated: 2024/06/07 17:11:38 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

static int	ft_count(unsigned int value)
{
	size_t	count;

	count = 0;
	while (value)
	{
		count++;
		value /= 10;
	}
	return (count);
}

void	ft_print_undec(unsigned int value, int *writtenCarac)
{
	*(writtenCarac) += ft_count(value);
	if (value < 10)
		ft_putchar_fd(value + '0', 1);
	else if (value >= 10)
	{
		ft_print_undec(value / 10, writtenCarac);
		ft_print_undec(value % 10, writtenCarac);
	}
}
