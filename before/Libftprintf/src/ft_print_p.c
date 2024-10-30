/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:42:49 by daavril           #+#    #+#             */
/*   Updated: 2024/06/10 13:49:30 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdint.h>

static size_t	ft_ptrlen(uintptr_t value)
{
	size_t	len;

	len = 0;
	while (value)
	{
		value /= 16;
		len++;
	}
	return (len);
}

static void	ft_putptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

void	ft_print_p(unsigned long long value, int *written_carac)
{
	if (value == 0)
		(*written_carac) += write(1, "(nil)", 5);
	else
	{
		(*written_carac) += write(1, "0x", 2);
		ft_putptr(value);
		(*written_carac) += ft_ptrlen(value);
	}
}
/*static size_t ft_len(char *value)
{
	size_t	len;

	len = 0;
	while (value[len] != '\0')
		len++;
	return(len);
}


char	*ft_print_p(char *value, int *writtenCarac)
{
	char    *adress;
	size_t  len;

	len = ft_len(value);
	adress[len - len] = "0";
	adress[len - (len - 1)] = "x";

}*/