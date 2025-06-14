/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:24:15 by daavril           #+#    #+#             */
/*   Updated: 2025/06/14 14:51:02 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		nb = 10;
	Zombie	*p = zombieHorde(nb, "José");

	for (int i = 0; i < nb; i++)
	{
		p[i].announce();
	}
	delete[] p;
	return (0);
}
