/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:43:09 by daavril           #+#    #+#             */
/*   Updated: 2024/06/08 05:31:09 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

static int  ft_len(unsigned int xXvalue)
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

void    ft_print_hexa(unsigned int value, int *writtenCarac, char c)
{
    (*writtenCarac) += ft_len(value);
    if (value >= 16)
	{
		ft_print_hexa((value / 16), writtenCarac, c);
		ft_print_hexa((value % 16), writtenCarac, c);
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
