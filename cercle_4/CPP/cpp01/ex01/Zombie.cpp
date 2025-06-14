/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:25:34 by daavril           #+#    #+#             */
/*   Updated: 2025/06/13 15:19:07 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//default constructor
Zombie::Zombie(void)
{
}

Zombie::Zombie(std::string n) : _name(n)
{
}

Zombie::~Zombie()
{
	std::cout << this->_name << " est mort" << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
	return ;
}
