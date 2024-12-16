/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:55:53 by terijo            #+#    #+#             */
/*   Updated: 2024/05/27 15:58:44 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
/*#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int c;

	c = '-';
	printf(" moi : %d\n", ft_isalnum(c));
	printf("vrai : %d", isalnum(c));
}*/
// fini !