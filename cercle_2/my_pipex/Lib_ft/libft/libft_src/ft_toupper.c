/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:57:54 by terijo            #+#    #+#             */
/*   Updated: 2024/09/12 14:16:25 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*The toupper() function converts a lower-case letter to the corresponding
		upper-case letter.  The argument must be representable as an unsigned
		char or the value of EOF.*/
int	ft_toupper(int c)
{
	c = c - 32;
	if (c >= 'A' && c <= 'Z')
		return (c);
	return (c + 32);
}
/*#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char    c;

	c = 'g';
	printf("moi : %d\n", ft_toupper(c));
	printf("vrai : %d", toupper(c));
	return (0);
}*/
// fini !!
