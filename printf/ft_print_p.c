/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:42:49 by daavril           #+#    #+#             */
/*   Updated: 2024/06/06 13:31:27 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files.h"
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

void	ft_print_p(unsigned long long value, int *writtenCarac)
{
	(*writtenCarac) += write(1, "0x", 2);
	if (value == 0)
		(*writtenCarac) += write(1, "0", 1);
	else
	{
		ft_putptr(value);
		(*writtenCarac) = ft_ptrlen(value);
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