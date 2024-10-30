/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:40:15 by terijo            #+#    #+#             */
/*   Updated: 2024/09/12 14:15:39 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	funct_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (funct_strlen(s1) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}
/*#include <string.h>
#include <stdio.h>

int	main(void)
{
	char    *s1 = "Bonjour comment ça va?";

	// char    *copie = strdup(s1);
	// printf("strdup copie :%s", copie);

	char    *copie = ft_strdup(s1);
	printf("ft_strdup copie :%s", copie);
	return (0);
}*/
// fini !
