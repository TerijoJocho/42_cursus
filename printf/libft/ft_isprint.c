/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:56:35 by terijo            #+#    #+#             */
/*   Updated: 2024/05/27 16:01:01 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}
/*#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char    c;

	c = 127;
	printf("moi : %d\n", ft_isprint(c));
	printf("vrai : %d", isprint(c));
	return (0);
}*/
// fini !