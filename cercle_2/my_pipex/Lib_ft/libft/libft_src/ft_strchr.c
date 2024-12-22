/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:56:46 by terijo            #+#    #+#             */
/*   Updated: 2024/09/12 14:15:36 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
/*#include <string.h>
#include <stdio.h>

int	main(void)
{
	char    s[] = "tripouille";
	int c;

	c = 't' + 256;
	printf("Vrai fonction :%s\n", strchr(s, c));
	printf("Ma fonction :%s", ft_strchr(s, c));
	return (0);
}*/
// finiii !!
