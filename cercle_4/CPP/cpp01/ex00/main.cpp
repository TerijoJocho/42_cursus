/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:24:15 by daavril           #+#    #+#             */
/*   Updated: 2025/05/28 16:49:26 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*p = newZombie("Jean");

	randomChump("Charles");//Charles meurt directement apres
	p->announce();
	delete p;//Jean meurt ici
	return (0);
}
