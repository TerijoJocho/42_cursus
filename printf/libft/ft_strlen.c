/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:57:09 by terijo            #+#    #+#             */
/*   Updated: 2024/05/27 16:03:17 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*#include <stdio.h>
int	main(void)
{
	char    str[] = "Bonjour";
	printf("%d", ft_strlen(str));
	return (0);
}*/
// fini !!