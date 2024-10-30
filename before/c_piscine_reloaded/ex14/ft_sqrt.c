/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 01:37:41 by terijo            #+#    #+#             */
/*   Updated: 2024/05/15 13:57:08 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	if (nb > 2147395600 || nb == 0 || nb < 0)
		return (0);
	i = 1;
	while (i * i < nb && i < 46340)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}
/*int     main(void)
{
	int     nb;

	nb = -9;
	printf("resultat :%d", ft_sqrt(nb));
	return(0);
}*/