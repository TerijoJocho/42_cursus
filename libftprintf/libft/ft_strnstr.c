/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:57:28 by terijo            #+#    #+#             */
/*   Updated: 2024/05/27 16:13:11 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] != '\0' && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
/*#include <string.h>
#include <stdio.h>

int	main(void)
{
		char haystack[] = "Bonjour tout le monde, ou les gens";
		char needle[] = " mon";

		//printf("vrai :%s\n", strnstr(haystack, needle));
		printf("moi :%s", ft_strnstr(haystack, needle, 5));
		return (0);
}*/
// fini mais j'ai utilisé int len au lieu de size_t len