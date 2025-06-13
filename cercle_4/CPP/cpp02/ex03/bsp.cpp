/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:13:04 by daavril           #+#    #+#             */
/*   Updated: 2025/06/13 19:39:09 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	cross(Point const &v1, Point const &v2)
{
	return (v1.getX() * v2.getY() - v1.getY() * v2.getX());
}

Point	makeVect(Point const &i, Point const &j)
{
	return (Point(i.getX().toFloat() - j.getX().toFloat(),
					i.getY().toFloat() - j.getY().toFloat()));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if ((a.getX() == point.getX() && a.getY() == point.getY())
		|| (b.getX() == point.getX() && b.getY() == point.getY())
			|| (c.getX() == point.getX() && c.getY() == point.getY()))
		return (false);

	Point	ab = makeVect(b, a);
	Point	ap = makeVect(point, a);
	Point	bc = makeVect(b, c);
	Point	bp = makeVect(b, point);
	Point	ca = makeVect(c, a);
	Point	cp = makeVect(c, point);

	Fixed	cross1 = cross(ab, ap);
	Fixed	cross2 = cross(bc, bp);
	Fixed	cross3 = cross(ca, cp);

	bool	has_neg = (cross1 < 0 || cross2 < 0 || cross3 < 0);
	bool	has_pos = (cross1 > 0 || cross2 > 0 || cross3 > 0);

	return !(has_neg && has_pos);
}

