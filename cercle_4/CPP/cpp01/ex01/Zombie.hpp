/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:25:26 by daavril           #+#    #+#             */
/*   Updated: 2025/06/13 15:18:27 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <new>

# pragma once

class Zombie
{
	public:
		Zombie(void);
		Zombie(std::string n);
		~Zombie();
		void	announce(void) const;
		void	setName(std::string name);

	private:
		std::string _name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
Zombie	*zombieHorde(int N, std::string name);

#endif
