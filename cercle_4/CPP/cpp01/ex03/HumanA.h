/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:18:31 by daavril           #+#    #+#             */
/*   Updated: 2025/05/30 14:21:08 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# pragma once

#include "Weapon.h"

class HumanA
{
	public:
		HumanA();
		~HumanA();
		Weapon	weapon;
		void	attack(void) const;
	private:
};

#endif
