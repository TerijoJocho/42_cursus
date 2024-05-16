/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:56:46 by terijo            #+#    #+#             */
/*   Updated: 2024/05/02 17:43:46 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The strchr() function locates the first occurrence of c
     (converted to a char) in the string pointed to by s.  The
     terminating null character is considered to be part of the
     string; therefore if c is ‘\0’, the functions locate the
     terminating ‘\0’.*/
char    *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while (s[i] != '\0' && s[i] != c)
        i++;
    if (s[i] == c)
    /*Consider this address (s[i]) as a pointer to a character*/
        return ((char *)&s[i]);
    else
        return (0);
}
/*#include <string.h>
#include <stdio.h>
int main(void)
{
    char    s[] = "Bon8 9jour ";
    int c;

    c = ' ';
    printf("Vrai fonction :%s\n", strchr(s, c));
    printf("Ma fonction :%s", ft_strchr(s, c));
    return (0);
}*/
//finiii !!