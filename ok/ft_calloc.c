/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:33:59 by terijo            #+#    #+#             */
/*   Updated: 2024/05/28 13:17:18 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*funct_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = b;
	while (len--)
		ptr[len] = (unsigned char)c;
	return (b);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (nmemb == 0 || size == 0)
	{
		size = 1;
		nmemb = 1;
	}
	total_size = nmemb * size;
	if (nmemb > 4294967295 / size)
		return (NULL);
	ptr = (void *)malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	funct_memset(ptr, 0, total_size);
	return (ptr);
}
/*#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	*ptr;

	ptr = (int *) calloc(0, -5);
	ptr[0] = 1;
	ptr[2] = 2;
	ptr[3] = 3;
	printf("ptr :%d, %d, %d", ptr[0], ptr[1], ptr[2]);
	//ptr = (int *)ft_calloc(3, sizeof(int));
	printf("ptr :%d, %d, %d", ptr[0], ptr[1], ptr[2]);
	free(ptr);
	return (0);
}*/
/*test checkcode */