#include "Fixed.h"

Fixed::Fixed(const Fixed &cpy)
{
	_nbFixed = cpy._nbFixed;
}

Fixed::Fixed(void) : _nbFixed(0)
{
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return (this->_nbBits);
}

void Fixed::setRawBits(int const raw)
{
	(void)raw;
	return ;
}
