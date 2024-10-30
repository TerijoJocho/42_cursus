/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:02:53 by daavril           #+#    #+#             */
/*   Updated: 2024/05/16 14:39:37 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char *))
{
	int	count;

	count = 0;
	while (*tab)
	{
		if (f(*tab) == 1)
			count++;
		tab++;
	}
	return (count);
}

/*int	renvoie_1(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
		i++;
	j = 5;
	if (i >= j)
		return (1);
	return (0);
}
#include <stdio.h>

int	main(void)
{
	char *str0 = "Bonjour";
	char *str1 = "Bon";
	char *str2 = "Bonjou";
	char *str3 = "Bonjo";
	char *str4 = "Bonj";
	char *tab[] = {str0, str1, str2, str3, str4, NULL};

	printf("%d", ft_count_if(tab, renvoie_1));
}*/