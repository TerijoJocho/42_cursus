/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:42:09 by terijo            #+#    #+#             */
/*   Updated: 2025/06/09 17:26:21 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// initialise la valeur à 0
Fixed::Fixed(void) : _rawBits(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

// initialise un objet en utilisant un autre objet de meme class
// rm : c'est en const car on ne veut pas modifier l'original
Fixed::Fixed(const Fixed &cpy)
{
	// std::cout << "Copy constructor called" << std::endl;
	// copie la valeur _rawBits de l'objet en pram dans le nouvelle objet
	this->_rawBits = cpy.getRawBits();
}

// prend un obejt deja existant
// lui attribut les valeur d'un autre objet
Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	// securité pour eviter l'auto affectation
	if (this != &other)
		this->_rawBits = other.getRawBits();
	// retourne une ref vers l'objet courant, ici c
	return (*this);
}

//transforme le floatVal en nb a virgule fixe
//roundf arrondi le float a l'entier le plus proche
//avec une precison de _fractionalBits
Fixed::Fixed(const float floatVal)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_rawBits = std::roundf(floatVal * (1 << _fractionalBits));
}

//converti le nb a virgule fixe en float
//en divisant par la precision, en float du coup
float	Fixed::toFloat(void) const
{
	return (this->_rawBits / float(1 << _fractionalBits));
}

Fixed::Fixed(const int intVal)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_rawBits = intVal << _fractionalBits; //decalage vers la gauche pour le stocker en fixed-point
}

int		Fixed::toInt(void) const
{
	return (this->_rawBits >>  _fractionalBits); //shift vers la droite pour avoir le int
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->_rawBits > other._rawBits);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_rawBits < other._rawBits);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_rawBits >= other._rawBits);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_rawBits <= other._rawBits);
}

bool Fixed::operator==(const Fixed &other) const 
{
	return (this->_rawBits == other._rawBits);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_rawBits != other._rawBits);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed	addition;
	
	addition.setRawBits(this->_rawBits + other._rawBits);
	return (addition);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed	soustraction;
	
	soustraction.setRawBits(this->_rawBits - other._rawBits);
	return (soustraction);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed	multiplication;
	
	multiplication.setRawBits((this->_rawBits * other._rawBits) >> _fractionalBits); //on divise une fois par la precision pour revenir a une bonne echelle
	return (multiplication);
}

Fixed Fixed::operator/(const Fixed &other) const 
{
	Fixed	division;
	division.setRawBits((this->_rawBits << _fractionalBits) / other._rawBits); //on multiplie par la precision avant la division, sinon on la perd
	return (division);
}

Fixed &Fixed::operator++(void)
{
	this->_rawBits++; //on incremente d'une unité fractionnaire = 1/256 = 0.0039...
	return (*this);
}   
        
Fixed Fixed::operator++(int)  
{
	Fixed	temp(*this);//on copie l'etat de l'objet
	this->_rawBits++; //on incremente d'une unité fractionnaire = 1/256 = 0.0039...
	return(temp);//on retourne l'etat d'avant
}
            
Fixed &Fixed::operator--(void)
{
	this->_rawBits--;
	return (*this);
}   
          
Fixed Fixed::operator--(int) 
{
	Fixed	temp(*this);
	this->_rawBits--;
	return(temp);
}

// destructeur
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

// getter pour la valeur du nombre a vrigule fixe
// sans la convertir
int Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

// initialise la valeur du nombre a virgule fixe
//à celle de celui passé en param
void Fixed::setRawBits(int const rawBits)
{
	this->_rawBits = rawBits;
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	if (first < second)
		return (first);
	return (second);
}

const Fixed &Fixed::minConst(Fixed const &first, Fixed const &second)
{
	return ((first < second) ? first : second);
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	if (first > second)
		return (first);
	return (second);
}

const Fixed &Fixed::maxConst(Fixed const &first, Fixed const &second)
{
	return ((first > second) ? first : second);
}

//precision des nvf
const int Fixed::_fractionalBits = 8;

//operateur << doit afficher la valeur float du nvf
std::ostream	&operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return (out);
}