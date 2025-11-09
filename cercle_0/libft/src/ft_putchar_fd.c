/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:43:22 by daavril           #+#    #+#             */
/*   Updated: 2024/05/27 16:02:21 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*int     main(void)
{
	char    c = 'c';

	ft_putchar_fd(c, 0);
	write(1, "\n", 1);
	ft_putchar_fd(c, 1);
	write(1, "\n", 1);
	ft_putchar_fd(c, 2);
	return (0);
}*/