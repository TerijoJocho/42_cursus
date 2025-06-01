/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:47:43 by daavril           #+#    #+#             */
/*   Updated: 2025/06/01 15:14:22 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string	type) : type(type)
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
