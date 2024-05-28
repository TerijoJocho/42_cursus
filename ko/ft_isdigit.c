/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:56:27 by terijo            #+#    #+#             */
/*   Updated: 2024/05/02 17:43:28 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The isdigit() function tests for a decimal digit character.
     Regardless of locale, this includes the following characters only:

     ``0''``1''``2''``3''``4''
     ``5''``6''``7''``8''``9''*/
int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}
/*#include <stdio.h>
#include <ctype.h>
int main(void)
{
    int c;

    c = 064;
    printf(" moi : %d\n", ft_isdigit(c));
    printf("vrai : %d", isdigit(c));
}*/
// fini !