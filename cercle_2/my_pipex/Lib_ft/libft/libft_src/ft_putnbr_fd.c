/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:54:35 by daavril           #+#    #+#             */
/*   Updated: 2024/09/12 14:15:28 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	nb;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = (-1) * n;
	}
	nb = '0' + n;
	if (n < 10)
		write(fd, &nb, 1);
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
/*int     main(void)
{
	int     n = -9;

	while (n <= 100)
	{
		ft_putnbr_fd(n, 1);
		write (1, "\n", 1);
		n++;
	}
	ft_putnbr_fd(n, 1);
	return (0);
}*/
