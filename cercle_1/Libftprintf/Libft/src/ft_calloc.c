/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:33:59 by terijo            #+#    #+#             */
/*   Updated: 2024/05/28 16:36:19 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static void	*funct_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = b;
	while (len--)
		ptr[len] = (unsigned char)c;
	return (b);
}*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	if (nmemb && size > 4294967295 / nmemb)
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
/*#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	*ptr;

	//ptr = (int *) calloc(0, sizeof(int));
	// ptr[0] = 1;
	// ptr[2] = 2;
	// ptr[3] = 3;
	printf("ptr :%d, %d, %d", ptr[0], ptr[1], ptr[2]);
	ptr = (int *)ft_calloc(0, 4);
	printf("ptr :%d, %d, %d", ptr[0], ptr[1], ptr[2]);
	free(ptr);
	return (0);
}*/
/*test checkcode */