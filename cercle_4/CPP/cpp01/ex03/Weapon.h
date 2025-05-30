/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:42:58 by daavril           #+#    #+#             */
/*   Updated: 2025/05/30 14:13:04 by daavril          ###   ########.fr       */
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
		~Weapon();
		const	std::string &getType(void) const;
		void	setType(std::string weapon);

	private:
		std::string	type;
};

#endif
