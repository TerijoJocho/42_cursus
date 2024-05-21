/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:27:20 by terijo            #+#    #+#             */
/*   Updated: 2024/05/21 13:44:27 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void    ft_putchar_fd(char c, int fd)
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
// fini