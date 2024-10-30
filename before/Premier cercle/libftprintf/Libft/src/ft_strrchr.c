/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:57:37 by terijo            #+#    #+#             */
/*   Updated: 2024/05/27 16:13:25 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	funct_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = funct_strlen(s) + 1;
	while (len--)
		if (*(s + len) == (char)c)
			return ((char *)(s + len));
	return (NULL);
}
/*#include <string.h>
#include <stdio.h>

int	main(void)
{
	char    s[] = "tripouille";
	int c;

	c = 'z';
	printf("Vrai fonction :%s\n", strrchr(s, c));
	printf("Ma fonction :%s", ft_strrchr(s, c));
	return (0);
}*/
// finiii !!