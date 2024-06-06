/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:46:38 by terijo            #+#    #+#             */
/*   Updated: 2024/05/27 16:06:50 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len--)
		*((unsigned char *)(b + len)) = (unsigned char)c;
	return (b);
}
/*#include <string.h>
#include <stdio.h>

int	main(void)
{
	int c;
	char b[5];
	char    a[6];

	c = '0';
	ft_memset(a, c, sizeof a);
	printf("ft_memset :%s\n", a);
	return (0);
}*/
/*test check*/