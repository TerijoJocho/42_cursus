/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:42:09 by terijo            #+#    #+#             */
/*   Updated: 2025/06/05 13:01:08 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//initialise la valeur à 0
Fixed::Fixed(void) : _nbFixed(0)
{
    std::cout << "Default constructor called" << std::endl;
}

//initialise un objet en utilisant un autre objet de meme class
//rm : c'est en const car on ne veut pas modifier l'original
Fixed::Fixed(const Fixed &cpy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_nbFixed = cpy.getRawBits();//copie la valeur _nbFixed de l'objet en pram dans le nouvelle objet
}

//prend un obejt deja existant
//lui attribut les valeur d'un autre objet
Fixed   &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    //securité pour eviter l'auto affectation
    if (this != &other)
        this->_nbFixed = other.getRawBits();
    //retourne une ref vers l'objet courant
    return (*this);
}

//destructeur
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//getter pour la valeur du nombre a vrigule fixe
//sans la convertir
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_nbFixed);
}

//initialise la valeur du nombre a virgule fixe
//à celle de celui passé en param
void    Fixed::setRawBits(int const raw)
{
    this->_nbFixed = raw;
}