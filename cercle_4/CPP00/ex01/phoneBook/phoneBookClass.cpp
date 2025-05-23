/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBookClass.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:18:11 by terijo            #+#    #+#             */
/*   Updated: 2025/05/23 20:32:06 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBookClass.hpp"
#include <iostream>
#include <fstream>

phoneBook::phoneBook(void) : count(0)
{
	std::clog << "Constructor phoneBook" << std::endl;
	return ;
}

phoneBook::~phoneBook(void)
{
	std::clog << "Destructor phoneBook" << std::endl;
	return ;
}

bool phoneBook::ft_add_contact(std::string fN, std::string lN, std::string nn,
	std::string pN, std::string dS)
{
	// if (this->count > 7)
	// 	return (false);//mettre un message d'erreur ou effacer le 1er contact pour le remplacer
	this->contact[this->count] = Contact(fN, lN, nn, pN, dS);
	this->count++;
	std::clog << "Contact added: " << fN << std::endl;
	return (true);
}

bool phoneBook::ft_search_contact(phoneBook &repertoire) const
{
	(void)repertoire;
	for (int i = 0; i < this->count; i++)
	{
		// std::cout << "|" << i << "|" << this->contact[i].firstName << "|" << this->contact[i].lastName << "|" << this->contact[i].nickname << "|" << std::endl;
		std::cout << "|";
		for (int j = 0; j < 10 - this->contact[i].firstName.length(); j++)
		{
			std::cout << " ";
		}
		std::cout << this->contact[i].firstName << this->contact[i].lastName << "|" << this->contact[i].nickname << "|" << std::endl;
	}
	return (true);
}


#include <iomanip> // à inclure dans le .cpp

// Dans ta boucle
std::cout << "|" << std::setw(10) << this->contact[i].firstName
          << "|" << std::setw(10) << this->contact[i].lastName
          << "|" << std::setw(10) << this->contact[i].nickname << "|" << std::endl;


bool phoneBook::ft_search_contact(phoneBook &repertoire) const
{
    (void)repertoire;
    for (int i = 0; i < this->count; i++)
    {
        std::cout << "|";

        // Affichage du firstName avec padding
        int padding = 10 - this->contact[i].firstName.length();
        for (int j = 0; j < padding; j++)
            std::cout << " ";
        std::cout << this->contact[i].firstName << "|";

        // Affichage du lastName avec padding
        padding = 10 - this->contact[i].lastName.length();
        for (int j = 0; j < padding; j++)
            std::cout << " ";
        std::cout << this->contact[i].lastName << "|";

        // Affichage du nickname avec padding
        padding = 10 - this->contact[i].nickname.length();
        for (int j = 0; j < padding; j++)
            std::cout << " ";
        std::cout << this->contact[i].nickname << "|" << std::endl;
    }
    return true;
}
