/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:22:28 by daavril           #+#    #+#             */
/*   Updated: 2024/06/06 13:49:58 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files.h"
#include "../libft/libft.h"

void    ft_type(char c, va_list value, int *writtenCarac)
{
    if (c == 'c')
    {
        (*writtenCarac)++;
        ft_print_char(va_arg(value, int));
    }
    else if (c == 's')
        ft_print_str(va_arg(value, char *), writtenCarac);
    else if (c == 'p')
        ft_print_p(va_arg(value, unsigned long long), writtenCarac);
    else if (c == 'd' || c == 'i')
        ft_print_id(va_arg(value, int), writtenCarac);
    //else if (c == 'u')
    //    ft_print_undec(va_arg(value, unsigned int), writtenCarac);
    //else if (c == 'x' || c == 'X')
    //    ft_print_hexa(va_arg(value, unsigned int), writtenCarac, c);
    //else if (c == '%')
    //{
        
    //}
}

int	ft_printf(const char *str, ...)
{
	int		writtenCarac;
	va_list	args;

	writtenCarac = 0;
	va_start(args, str);
    while (*str)
    {
        if (*str != '%')
        {
            ft_print_char(str[0]);
            writtenCarac++;
        }
        else
            ft_type(*++str, args, &writtenCarac);
        str++;
    }
    va_end(args);
    return (writtenCarac);
}

