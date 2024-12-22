/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:44:35 by terijo            #+#    #+#             */
/*   Updated: 2024/09/12 14:15:11 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*static void	*funct_memcpy(void *dst, const void *src, size_t n)
{
	while (n--)
		*((unsigned char *)(dst + n)) = *((unsigned char *)(src + n));
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	a[];

	funct_memcpy(a, src, len);
	funct_memcpy(dst, a, len);
	return (dst);
}*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (s1 <= s2 || s1 >= (s2 + len))
		while (len--)
			*s1++ = *s2++;
	else
	{
		s1 += len - 1;
		s2 += len - 1;
		while (len--)
			*s1-- = *s2--;
	}
	return (dst);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char dst[] = "caca";
	char str[] = "Parle à ma main";

	// Affichage des données avant la copie
	printf("Avant la copie : str = %s, ptr = %s\n", str, dst);

	// Copie des 5 premiers caractères de "str" dans "dst"
	//memmove(dst, str, 5);
	ft_memmove(dst, str, 5);

	// Affichage des données après la copie
	printf("Après la copie : str = %s, ptr = %s\n", str, dst);

	return (0);
}*/
