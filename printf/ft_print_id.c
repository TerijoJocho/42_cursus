/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:42:54 by daavril           #+#    #+#             */
/*   Updated: 2024/06/06 13:21:41 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "files.h"

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

void	ft_print_id(int value, int *writtenCarac)
{
	*(writtenCarac) += ft_count(value);
	ft_putnbr_fd(value, 1);
}