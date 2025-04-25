/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:57:21 by terijo            #+#    #+#             */
/*   Updated: 2024/09/12 14:16:03 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == 0 && s2 == 0)
		return (0);
	while (i < n && s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	if (n == i)
		return (0);
	return ((*(unsigned char *)(s1 + i)) - (*(unsigned char *)(s2 + i)));
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[] = "1234";
	char	s2[] = "1234";

	printf("vrai :%d\n", strncmp(s1, s2, 3));
	printf("moi :%d\n", ft_strncmp(s1, s2, 3));
}*/
