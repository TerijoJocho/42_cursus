#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{

}

Point::Point(Point const &cpy) : _x(cpy.getX()), _y(cpy.getY())
{
	// *this = cpy; pas bon
}

//impossible d'utiliser car x et y const
Point &Point::operator=(Point const &other)
{
	(void)other;
	return (*this);
}

Point::~Point()
{

}

Fixed Point::getX(void) const
{
	return (this->_x);
}

Fixed Point::getY(void) const
{
	return (this->_y);
}

