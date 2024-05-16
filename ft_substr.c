/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:01:51 by terijo            #+#    #+#             */
/*   Updated: 2024/05/05 22:05:30 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *ptr;
    size_t i;
    
    if (s == NULL)
        return (NULL);
    ptr = (char *) malloc(sizeof(*s) * len + 1);
    if (ptr == NULL)
        return NULL;
    i = 0;
    while (i < len && s[start + i] != '\0')
    {
        ptr[i] = s[start + i];
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}
/*#include <stdio.h>
int     main(void)
{
    int     start = 3;
    char    *s = "Bonjour";
    size_t len = 4;
    
    printf("mot :%s\n", s);
    printf("copie :%s", ft_substr(s, start, len));
    return(0);
}*/
//fini !