/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:13:04 by daavril           #+#    #+#             */
/*   Updated: 2025/06/11 17:16:16 by daavril          ###   ########.fr       */
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

	return (true);
}
