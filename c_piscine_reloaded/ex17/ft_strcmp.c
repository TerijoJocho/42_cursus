/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 02:19:32 by terijo            #+#    #+#             */
/*   Updated: 2024/05/14 15:44:34 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
/*#include <stdio.h>
int	main(void)
{
	char    *s1 = "bonjour";
	char    *s2 = "bonsoir";

	printf("s1 :%s \ns2 :%s\n", s1, s2);
	printf("%d", ft_strcmp(s1, s2));
	return(0);
}*/