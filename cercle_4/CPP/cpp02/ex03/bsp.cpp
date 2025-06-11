/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:13:04 by daavril           #+#    #+#             */
/*   Updated: 2025/06/11 18:54:13 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	vectProduct(Point const &i, Point const &j)
{
	std::cout << "res: " << i.getX() * j.getY() - i.getY() * j.getX() << std::endl;
	return (i.getX() * j.getY() - i.getY() * j.getX());
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if ((a.getX() == point.getX() && a.getY() == point.getY())
		|| (b.getX() == point.getX() && b.getY() == point.getY())
			|| (c.getX() == point.getX() && c.getY() == point.getY()))
		return (false);
	Point	v0(b - a);
	return (true);
}

/*Construire les vecteurs suivants :

    v0 = b - a

    v1 = c - b

    v2 = a - c

    p0 = point - a

    p1 = point - b

    p2 = point - c

Faire les produits vectoriels :

    cross1 = cross(v0, p0)

    cross2 = cross(v1, p1)

    cross3 = cross(v2, p2)

Tester si tous les cross ont le même signe.*/
