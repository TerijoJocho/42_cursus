#ifndef POINT_HPP
# define POINT_HPP

# pragma once
#include "Fixed.hpp"

class Point
{
  public:
	Point(void);
	Point(float const x, float const y);
	Point(Point const &cpy);
	Point &operator=(Point const &other);
	Point operator-(const Point &other) const;
	~Point();

	Fixed	getX(void) const;
	Fixed	getY(void) const;

  private:
	Fixed const	_x;
	Fixed const	_y;
};

#endif
