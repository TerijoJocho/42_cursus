/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 03:02:38 by terijo            #+#    #+#             */
/*   Updated: 2024/05/16 16:04:06 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(sizeof(*s1) * sizeof(char));
	if (!ptr)
		return (0);
	while (s1[i])
	{
		*(ptr + i) = s1[i];
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}
/*#include <stdio.h>
int	main(void)
{
	char    *s1 = "Bonjour comment ça va?!";

	// char    *copie = strdup(s1);
	// printf("strdup copie :%s", copie);

	char    *copie = ft_strdup(s1);
	printf("ft_strdup copie :%s", copie);
	return (0);
}*/