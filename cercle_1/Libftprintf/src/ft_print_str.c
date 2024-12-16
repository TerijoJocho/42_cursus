/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:26:03 by daavril           #+#    #+#             */
/*   Updated: 2024/06/10 14:15:01 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_str(char *value, int *written_carac)
{
	int	i;

	i = 0;
	if (!value)
		value = "(null)";
	while (value[i] != '\0')
	{
		ft_print_char(value[i]);
		(*written_carac)++;
		i++;
	}
	return (1);
}
