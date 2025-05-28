/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:46:02 by daavril           #+#    #+#             */
/*   Updated: 2025/05/28 16:45:19 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//le zombie cree ici s'annonce tout seul directement
//il meurt direct apres cette fonction car son destructeur
//est appele directement apres et tout seul
//Interet :
//leger, simple, rapide, meurt tout seul
//on ne peut pas y acceder une fois la fonction terminee
//bien pour les objets temp
void	randomChump(std::string name)
{
	Zombie	z(name);

	z.announce();
	return ;
}
