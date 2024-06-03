/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:42:54 by daavril           #+#    #+#             */
/*   Updated: 2024/06/03 19:11:29 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files.h"
#include "../libft/libft.h"

static int	ft_count(int value)
{
	size_t	count;

	count = 0;
	while (value)
	{
		count++;
		value /= 10;
	}
	return (count);
}

int	ft_print_id(int value, int *writtenCarac)
{
	ft_putnbr_fd(value, 1);
	*(writtenCarac) += ft_count(value);
}