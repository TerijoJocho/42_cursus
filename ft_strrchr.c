/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:57:37 by terijo            #+#    #+#             */
/*   Updated: 2024/05/02 17:44:12 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The strrchr() function is identical to strchr(), except it
     locates the last occurrence of c.*/
char    *ft_strrchr(const char *s, int c)
{
    int i;
    int n;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            n = i;
        i++;
    }
    if (s[i] == '\0')
        return ((char *)&s[i]);
    else
        return ((char *)&s[n]);
}
/*#include <string.h>
#include <stdio.h>
int main(void)
{
    char    s[] = "Bon8 9jour ";
    int c;

    c = ' ';
    printf("Vrai fonction :%s\n", strrchr(s, c));
    printf("Ma fonction :%s", ft_strrchr(s, c));
    return (0);
}*/
//finiii !!