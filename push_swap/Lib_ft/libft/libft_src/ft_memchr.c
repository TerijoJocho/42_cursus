/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:11:03 by terijo            #+#    #+#             */
/*   Updated: 2024/09/12 14:14:58 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if ((*(unsigned char *)s) == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char    s[] = "bonjour tout le monde";
	int    c = 't';

	printf("%s\n", s);
	void *result = memchr(s, c, sizeof s);
	char *ptr = (char *) result;
	printf("memchr :%s\n", ptr);

	printf("%s\n", s);
	void *result2 = ft_memchr(s, c, sizeof s);
	char *ptr2 = (char *) result2;
	printf("ft_memchr :%s", ptr2);
	return (0);
}*/
// fini !
