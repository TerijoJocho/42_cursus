/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:32:12 by terijo            #+#    #+#             */
/*   Updated: 2024/05/27 16:06:21 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char    s1[] = "Bonjour";
	char    s2[] = "Bonsoir toi";

	printf("s1 :%s\ns2 :%s\n", s1, s2);
	printf("memcmp :%d", memcmp(s1, s2, 9));

	printf("s1 :%s\ns2 :%s\n", s1, s2);
	printf("ft_memcmp :%d", ft_memcmp(s1, s2, 9));
	return (0);
}*/
// fini !