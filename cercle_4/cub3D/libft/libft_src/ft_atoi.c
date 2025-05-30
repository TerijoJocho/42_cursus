/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:43:07 by daavril           #+#    #+#             */
/*   Updated: 2025/05/30 20:20:54 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long	ft_atoi(const char *str)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		return (-1);
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		if (nb > __INT_MAX__)
			return (-1);
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return (nb);
}
/*#include <stdio.h>
int	main(int argc, char **argv)
{
	if(argc == 2)
		printf("%d", ft_atoi(argv[1]));
	return (0);
}*/
/*#include <stdio.h>
int	main(void)
{
	printf("%d", ft_atoi("\007 8"));
	printf("%d", atoi("\007 8"));
}*/
