/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:45:51 by daavril           #+#    #+#             */
/*   Updated: 2025/05/28 16:46:34 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//peut manipuler le zombie comme on veut
//on controle sa durer de vie (avec delete)
//Interet
//on peut le garder longtemps
//utile si on veut passer l'objet a d'autre fonction, ou le stocker
//on doit le "delete"
//ideale pour les objet a manipuler longtemps
Zombie	*newZombie(std::string name)
{
	Zombie	*p = new Zombie(name);

	return (p);
}
