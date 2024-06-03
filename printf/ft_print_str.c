/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:26:03 by daavril           #+#    #+#             */
/*   Updated: 2024/06/03 19:11:44 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files.h"

int	ft_print_str(char *value, int *writtenCarac)
{
	int	i;

	i = 0;
	if (!value)
		value = "(null)";
	while (value[i] != '\0')
	{
		ft_print_char(value[i]);
		*(writtenCarac)++;
		i++;
	}
	return (1);
}
