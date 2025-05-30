/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:47:43 by daavril           #+#    #+#             */
/*   Updated: 2025/05/30 14:13:07 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

//1er const : const de retour, bloque la valeur retourner
//protege le retour
//2e const : const qui ne permet pas la modif de l'instance
//protege l'objet this
const std::string	&Weapon::getType(void) const
{
	return (this->type);
}

void	Weapon::setType(std::string weapon)
{
	this->type = weapon;
	return ;
}
