/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:43:09 by daavril           #+#    #+#             */
/*   Updated: 2024/09/11 13:21:19 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../Libft/header/libft.h"

static int	ft_len(unsigned int xXvalue)
{
	size_t	len;

	len = 0;
	while (xXvalue)
	{
		xXvalue /= 16;
		len++;
	}
	return (len);
}

void	ft_put_hex(unsigned int value, char c)
{
	if (value >= 16)
	{
		ft_put_hex((value / 16), c);
		ft_put_hex((value % 16), c);
	}
	else
	{
		if (value <= 9)
			ft_putchar_fd((value + '0'), 1);
		else
		{
			if (c == 'x')
				ft_putchar_fd((value - 10 + 'a'), 1);
			if (c == 'X')
				ft_putchar_fd((value - 10 + 'A'), 1);
		}
	}
}

void	ft_print_hexa(unsigned int value, int *written_carac, char c)
{
	if (value == 0)
		(*written_carac) += write(1, "0", 1);
	else
		ft_put_hex(value, c);
	(*written_carac) += ft_len(value);
}
