/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:56:35 by terijo            #+#    #+#             */
/*   Updated: 2024/05/02 17:43:30 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The isprint() function tests for any printing character, including space
     (‘ ’).  The value of the argument must be representable as an unsigned
     char or the value of EOF.*/
int ft_isprint(int c)
{
    if (c >= ' ' && c <= '~')
        return (1);
    return (0);
}
/*#include <ctype.h>
#include <stdio.h>
int main(void)
{
    char    c;

    c = 127;
    printf("moi : %d\n", ft_isprint(c));
    printf("vrai : %d", isprint(c));
    return (0);
}*/
// fini !