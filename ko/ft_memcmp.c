/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:32:12 by terijo            #+#    #+#             */
/*   Updated: 2024/05/04 15:27:52 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int     ft_memcmp(const void *s1, const void *s2, size_t n)
{
   size_t			i;

	i = 0;
	while (i < n)
	{
        /*s1 + i allow to access the value at i, s1[i]*/
		if (*(unsigned char*)(s1 + i) != *(unsigned char*)(s2 + i))
			return (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i));
            //return (s1 - s2); return the diference between address not value
		i++;
	}
    return (0);
}
/*#include <stdio.h>
#include <string.h>
int     main(void)
{
    char    s1[] = "Bonjour";
    char    s2[] = "Bonsoir toi";

    printf("s1 :%s\ns2 :%s\n", s1, s2);
    printf("memcmp :%d", memcmp(s1, s2, 9));

    printf("s1 :%s\ns2 :%s\n", s1, s2);
    printf("ft_memcmp :%d", ft_memcmp(s1, s2, 9));
    return (0);
}*/
//fini !