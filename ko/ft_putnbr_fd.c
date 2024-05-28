/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:41:46 by terijo            #+#    #+#             */
/*   Updated: 2024/05/21 15:59:13 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void ft_putnbr_fd(int n, int fd)
{
    char    nb;

    nb = '0' + n;
    if (n < 0)
    {
        write(fd, "-", 1);
        n = (-1) * n;
    }
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
    int     n = -42;
    ft_putnbr_fd(n, 1);
}*/