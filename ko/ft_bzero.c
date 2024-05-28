/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:39:36 by terijo            #+#    #+#             */
/*   Updated: 2024/05/04 15:49:47 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void    ft_bzero(void *s, size_t n)
{
    while (n--)
        *((unsigned char *)(s + n)) = 0;
}
/*#include <stdio.h>
#include <string.h>
int main(void)
{
    int i;
    char    s[5];

    printf("s :%d, %d, %d, %d ,%d\n", s[0], s[1], s[2], s[3], s[4]);
    //bzero(s, sizeof(s));
    ft_bzero(s , sizeof(s));
    printf("ft_bzero :%d, %d, %d, %d ,%d\n", s[0], s[1], s[2], s[3], s[4]);
    return(0);
}*/
//fini 