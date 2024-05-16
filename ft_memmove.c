/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:44:35 by terijo            #+#    #+#             */
/*   Updated: 2024/05/02 18:09:29 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void    *ft_memmove(void *dst, const void *src, size_t len)
{
    while (len--)
        *((unsigned char *)(dst + len)) = *((unsigned char *)(src + len));
    return (dst);
}
//chatgpt
/*#include <stdio.h>
#include <string.h>
int main(void)
{
    char dst[] = "caca"; 
    char str[] = "Parle à ma main"; 

    // Affichage des données avant la copie
    printf("Avant la copie : str = %s, ptr = %s\n", str, dst);

    // Copie des 5 premiers caractères de "str" dans "dst"
    memmove(dst, str, 5);
    //ft_memmove(dst, str, 5);

    // Affichage des données après la copie
    printf("Après la copie : str = %s, ptr = %s\n", str, dst);

    return 0;
}*/
//idk, comprend la diff avec memcpy, but ca fonctionne
// A REVOIR