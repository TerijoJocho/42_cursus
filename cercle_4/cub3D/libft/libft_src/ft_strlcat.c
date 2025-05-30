/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:56:55 by terijo            #+#    #+#             */
/*   Updated: 2025/02/18 16:18:21 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	srclen = 0;
	dstlen = 0;
	while (dst[dstlen] && dstlen < dstsize)
		dstlen++;
	while (src[srclen])
		srclen++;
	if (dstsize == 0)
		return (srclen);
	i = dstlen;
	while (src[i - dstlen] && i < dstsize - 1)
	{
		dst[i] = src[i - dstlen];
		i++;
	}
	if (dstlen < dstsize)
		dst[i] = '\0';
	return (dstlen + srclen);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char    src[] = "bonjoyur";
	char    dst[] = "twhx";


	printf("dst avant :%s\n", dst);
	//printf("strlcat :%d\n", strlcat(dst, src, 0));
	printf("ft_strlcat :%lu\n", ft_strlcat(dst, src, 4));
	printf("dst apres :%s", dst);
	return (0);
}*/
/*test check*/
