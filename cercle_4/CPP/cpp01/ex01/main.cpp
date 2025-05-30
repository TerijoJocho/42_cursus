/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:24:15 by daavril           #+#    #+#             */
/*   Updated: 2025/05/30 13:07:21 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		nb = 5;
	Zombie	*p = zombieHorde(nb, "José");

	for (int i = 0; i < nb; i++)
	{
		p->announce();
	}
	delete[] p;
	return (0);
}
