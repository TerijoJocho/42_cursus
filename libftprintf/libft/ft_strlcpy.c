/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:57:02 by terijo            #+#    #+#             */
/*   Updated: 2024/05/27 16:10:35 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != 0 && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != 0)
		i++;
	return (i);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char    src[] = "coucou";
	char    dst[] = "AAAAAAAAAA";

	printf("src :%s\n", src);
	printf("dst avant :%s\n", dst);

	//printf("strlcpy:%d\n", strlcpy(dst, src, 0));

	printf("ft_strlcpy:%lu\n", ft_strlcpy(dst, src, 0));
	printf("dst apres :%s", dst);
	return (0);
}*/