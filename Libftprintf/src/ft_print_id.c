/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:42:54 by daavril           #+#    #+#             */
/*   Updated: 2024/06/10 14:34:44 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

static int	ft_count(int value)
{
	int	count;

	count = 0;
	if (value <= 0)
		count++;
	while (value)
	{
		count++;
		value /= 10;
	}
	return (count);
}

void	ft_print_id(int value, int *written_carac)
{
	ft_putnbr_fd(value, 1);
	*(written_carac) += ft_count(value);
}
