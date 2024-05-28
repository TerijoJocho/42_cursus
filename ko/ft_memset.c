/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:46:38 by terijo            #+#    #+#             */
/*   Updated: 2024/05/02 17:59:00 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void    *ft_memset(void *b, int c, size_t len)
{
    while (len--)
        /*unsigned char to do arithmetical calculus, octet by octet, starting by len*/
        *((unsigned char*)(b + len)) = (unsigned char) c;
    return (b);
}
/*#include <string.h>
#include <stdio.h>
int main(void)
{
    int c;
    char b[5];
    char    a[6];

    c = '0'; // Initialisation de c avec la valeur 'f'
    //memset(b, c, sizeof b); // Remplissage de b avec la valeur de c
    //printf("memset :%s\n", b); // Affichage de la chaîne b

    ft_memset(a, c, sizeof a);
    printf("ft_memset :%s\n", a);
    return 0;
}*/
// fini