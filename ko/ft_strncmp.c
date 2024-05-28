/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:57:21 by terijo            #+#    #+#             */
/*   Updated: 2024/05/02 17:44:05 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The strcmp() and strncmp() functions lexicographically compare
     the null-terminated strings s1 and s2.

     The strncmp() function compares not more than n characters.
     Because strncmp() is designed for comparing strings rather than
     binary data, characters that appear after a ‘\0’ character are
     not compared.*/
int ft_strncmp(const char *s1, const char *s2, int n)
{
    int i;

    i = 0;
    while ((s1[i] && s2[i]) && s1[i] == s2[i] && i < n)
        i++;
    return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
/*#include <string.h>
#include <stdio.h>
int main(void)
{
    char s1[] = "bonjour!";
    char s2[] = "bonjour!";

    printf("vrai :%d\n", strncmp(s1, s2, 3));
    printf("moi :%d\n", ft_strncmp(s1, s2, 3));
}*/
// fini mais j'ai utilisé int n au lieu de size_t n, je ne comprend 
//pas ce que c'est