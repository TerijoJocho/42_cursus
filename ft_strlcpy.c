/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:57:02 by terijo            #+#    #+#             */
/*   Updated: 2024/05/02 17:47:24 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*en gros copie dstsize caract ('\0' est compris dedans) de src dans dst et renvoie le nombre
de caract qu'on aurait pu copier si dst était asser long(=len de src)*/
size_t  ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
{
    int i;

    i = 0;
    while (src[i] != 0 && i < dstsize - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    while (src[i] != 0)
        i++;    
    return (i);
}
/*#include <stdio.h>
#include <string.h>
int main(void)
{
    char    src[] = "azertyl";
    char    dst[] = "loljj";

    printf("src :%s\n", src);
    printf("dst avant :%s\n", dst);
    printf("strlcpy:%lu\n", strlcpy(dst, src, 5));
    //printf("ft_strlcpy:%lu\n", ft_strlcpy(dst, src, 5));
    printf("dst apres :%s", dst);
    return (0);
}*/
//fini mais j'ai utilisé long et int au lieu de size_t...