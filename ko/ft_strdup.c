/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:40:15 by terijo            #+#    #+#             */
/*   Updated: 2024/05/05 22:04:50 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char    *ft_strdup(const char *s1)
{
    size_t  i;
    char    *ptr;

    i = 0;
    ptr = (char *) malloc(sizeof(*s1) * sizeof(char));
    if (!ptr)
        return NULL;
    while (s1[i])
    {
        *(ptr + i) = s1[i];
        /*ptr[i] = s1[i]*/
        i++;
    }
    *(ptr + i) = '\0';
    return (ptr);
}   
/*#include <string.h>
#include <stdio.h>
int main(void)
{
    char    *s1 = "Bonjour comment ça va?";
    
    // char    *copie = strdup(s1);
    // printf("strdup copie :%s", copie);
    
    char    *copie = ft_strdup(s1);
    printf("ft_strdup copie :%s", copie);
    return (0);
}*/
//fini !