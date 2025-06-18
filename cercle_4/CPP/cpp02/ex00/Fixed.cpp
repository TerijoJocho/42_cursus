/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:42:09 by terijo            #+#    #+#             */
/*   Updated: 2025/06/18 12:10:45 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// initialise la valeur à 0
Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// initialise un objet en utilisant un autre objet de meme class
// rm : c'est en const car on ne veut pas modifier l'original
Fixed::Fixed(const Fixed &cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	// copie la valeur _rawBits de l'objet en param dans le nouvelle objet
	this->_rawBits = cpy.getRawBits();
}

// prend un obejt deja existant
// lui attribut les valeur d'un autre objet
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	// securité pour eviter l'auto affectation
	if (this != &other)
		this->_rawBits = other.getRawBits();
	// retourne une ref vers l'objet courant, ici c
	return (*this);
}

// destructeur
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// getter pour la valeur du nombre a vrigule fixe
// sans la convertir
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

// initialise la valeur du nombre a virgule fixe
//à celle de celui passé en param
void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

static const int _fractionalBits(8); //initialise le nb de bits de la partie fractionnaire
