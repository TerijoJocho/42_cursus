/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:56:18 by terijo            #+#    #+#             */
/*   Updated: 2024/05/02 17:43:24 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The isascii() function tests for an ASCII character, which is any
character between 0 and octal 0177 inclusive.*/
int ft_isascii(int c)
{
    /*test en octal*/
    if (c >= '\0' && c <= '~')
        return (1);
    else if (c == 127 || c == 177) // il manque le DEL du hexadecimal
        return (1);
    return (0);
}
/*#include <stdio.h>
#include <ctype.h>
int main(void)
{
    int c;

    c = 127;
    printf(" moi : %d\n", ft_isascii(c));
    printf("vrai : %d", isascii(c));
}*/