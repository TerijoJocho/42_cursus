/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:11:37 by terijo            #+#    #+#             */
/*   Updated: 2024/05/27 16:06:44 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	while (n--)
		*((unsigned char *)(dst + n)) = *((unsigned char *)(src + n));
	return (dst);
}
/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char    src[] = "Bonjour";
	char    dst[] = "world";

	printf("src :%s\n", src);
	printf("dst :%s\n", dst);
	//memcpy(dst, src, 4);
	ft_memcpy(dst, src, 3);
	printf("dst :%s\n", dst);
	return (0);
}*/
// fini, c'est comme le strncopy en gros, sauf que lorsqu'il y a chevauchement
// le comportement est indefinie, pour le coup ici ca fonctionne

// pour comparer avec memmove mais comprend rien
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char dst[] = "caca";
	char str[] = "Parle à ma main";

	// Affichage des données avant la copie
	printf("Avant la copie : str = %s, ptr = %s\n", str, dst);

	// Copie des 5 premiers caractères de "str" dans "dst"
	memcpy(dst, str, 3);
	//ft_memcpy(dst, str, 3);

	// Affichage des données après la copie
	printf("Après la copie : str = %s, ptr = %s\n", str, dst);

	return (0);
}*/
// fini mais comprend la diff avec move