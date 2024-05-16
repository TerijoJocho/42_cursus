/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:53:28 by terijo            #+#    #+#             */
/*   Updated: 2024/05/05 23:48:07 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t      ft_cmp_char_set(char c, char const *set)
{
    size_t i;
    
    i = 0;
    while (set[i] != '\0')
    {
        if (c == set[i])
            return (1);
        i++;
    }
    return (0);
}
char    *ft_strtrim(char const *s1, char const *set)
{
    size_t  start;
    size_t  end;
    size_t  i;
    char    *ptr;

    start = 0;
    while (s1[start] && ft_cmp_char_set(s1[start], set))
        start++;
    end = ft_strlen(s1) - 1;
    while (end > start  && ft_cmp_char_set(s1[end - 1], set))
        end--;
    ptr = (char *)malloc(sizeof(*ptr) * ft_strlen(s1) + 1);
    if (ptr == NULL)
        return NULL;
    i = 0;
    while (start < end)
    {
        ptr[i] = s1[start];
        i++;
        start++;
    }
    ptr[i] = '\0';
    return (ptr);
}
/*#include <stdio.h>
int     main(void)
{
    char    *s = "   bonjour   ";
    char    *set = " ";

    printf("str :%s.", s);
    printf("\ncopie trimmé :%s", ft_strtrim(s, set));
    return(0);
}*/
//fini !