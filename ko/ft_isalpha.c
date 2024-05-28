/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:56:07 by terijo            #+#    #+#             */
/*   Updated: 2024/05/02 17:43:21 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The isalpha() function tests for any character for which isupper(3) or islower(3) is
true.  The value of the argument must be representable as an unsigned char or the value
of EOF.*/
int ft_isalpha(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}
/*#include <stdio.h>
#include <ctype.h>
int main(void)
{
    int c;

    c = 167;    //67 fonctionne mais pas 167 wtf
    printf(" moi : %d\n", ft_isalpha(c));
    printf("vrai : %d", isalpha(c));
}*/
//fini !