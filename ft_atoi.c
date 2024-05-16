/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:53:14 by terijo            #+#    #+#             */
/*   Updated: 2024/05/02 17:40:59 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int    ft_atoi(const char *str)
{
    int i;
    int sign;
    int nb;

    i = 0;
    sign = 1;
    nb = 0;
    while ((str[i] >= 7 && str[i] <= 13) || str [i] == 32)
        i++;
    if (str[i] == '-')
    {
        sign *= - 1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        nb = (nb * 10) + str[i] - '0';
        i++;
    }
    return (nb * sign);
}
/*#include <stdio.h>
int main(int argc, char **argv)
{
    if(argc == 2)
        printf("%d", ft_atoi(argv[1]));
    return(0);
}*/
//fini !!