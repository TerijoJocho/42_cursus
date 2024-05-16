/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:57:44 by terijo            #+#    #+#             */
/*   Updated: 2024/05/02 17:44:16 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The tolower() function converts an upper-case letter to the
     corresponding lower-case letter.  The argument must be representable as
     an unsigned char or the value of EOF.*/
int ft_tolower(int c)
{
    c = c + 32;
    if (c >= 'a' && c <= 'z')
        return (c);
    return(c - 32);
}
/*#include <ctype.h>
#include <stdio.h>
int main(void)
{
    char    c;

    c = 'H';
    printf("moi : %d\n", ft_tolower(c));
    printf("vrai : %d", tolower(c));
    return (0);
}*/
//fini !!