/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:56:55 by terijo            #+#    #+#             */
/*   Updated: 2024/05/02 17:36:16 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t  ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize)
{
    int i;
    int srclen;
    int dstlen;

    srclen = 0;
    dstlen = 0;
    while (dst[dstlen] && dstlen < dstsize)
        dstlen++;
    while (src[srclen])
        srclen++;
    /*this line means that we must have srclen size, for dst, to append src to dst*/
    if (dstsize == 0)
        return (srclen);
    /*we don't want to change dstlen*/
    i = dstlen;
    /*first condition to navigate into src and second one to strcat only 
    dstsize - '\0'*/
    while (src[i - dstlen] && i < dstsize - 1)
    {
        dst[i] = src[i - dstlen];
        i++;
    }
    if (dstlen < dstsize)
        dst[i] = '\0';
    return (dstlen + srclen);
}
/*#include <stdio.h>
#include <string.h>
int main(void)
{
    char    src[] = "Bonjour";
    char    dst[] = "test";
    

    printf("dst avant :%s\n", dst);
    printf("strlcat :%d\n", strlcat(dst, src, 5));
    //printf("ft_strlcat :%lu\n", ft_strlcat(dst, src, 5));
    printf("dst apres :%s", dst);
    return (0);
}*/
//fini mais a revoir