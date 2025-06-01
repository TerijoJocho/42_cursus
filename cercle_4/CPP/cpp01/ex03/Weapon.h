/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:42:58 by daavril           #+#    #+#             */
/*   Updated: 2025/06/01 15:08:08 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# pragma once

#include <iostream>

class Weapon
{
	public:
		Weapon();
		Weapon(std::string	type);
		~Weapon();
		const	std::string &getType(void) const;
		void	setType(std::string weapon);

	private:
		std::string	type;
};

#endif
