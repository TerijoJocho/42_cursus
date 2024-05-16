/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:06:09 by terijo            #+#    #+#             */
/*   Updated: 2024/05/05 23:03:04 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t i;
    size_t j;
    char    *ptr;
    
    ptr = (char *)malloc(sizeof(*ptr) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (ptr == NULL)
        return NULL;
    i = 0;
    while (s1[i] != '\0')
    {
        ptr[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j] != '\0')
    {
        ptr[i + j] = s2[j];
        j++;
    }
    ptr[i + j] = '\0';
    return (ptr);
}
/*#include <stdio.h>
int     main(void)
{
    char    *s1 = "bon";
    char    *s2 = "jour";
    
    printf("s1 :%s\ns2 :%s", s1, s2);
    printf("\nresultat :%s", ft_strjoin(s1, s2));
    return (0);
}*/
//fini ! Fonctionne en faisant gcc -Wall -Wextra -Werror -I. ft_strlen.c ft_strjoin.c