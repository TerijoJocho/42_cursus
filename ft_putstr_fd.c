/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:51:33 by terijo            #+#    #+#             */
/*   Updated: 2024/05/21 14:04:02 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void ft_putstr_fd(char *s, int fd)
{
    int     i;

    i = 0;
    while (s[i])
    {
        write(fd, &s[i], 1);
        i++;
    }
}
/*int     main(void)
{
    char    *s = "Bonjour";

    ft_putstr_fd(s, 0);
    return (0);
}*/
//fini