/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_undec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:42:59 by daavril           #+#    #+#             */
/*   Updated: 2024/09/11 13:21:29 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../Libft/header/libft.h"

void	ft_print_undec(unsigned int value, int *written_carac)
{
	if (value >= 10)
		ft_print_undec(value / 10, written_carac);
	ft_putchar_fd((value % 10) + '0', 1);
	(*written_carac)++;
}
