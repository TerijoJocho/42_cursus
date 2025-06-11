/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:18:18 by terijo            #+#    #+#             */
/*   Updated: 2025/06/11 17:00:31 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point	a(1.2, 3.1);
	Point	b(5.3, 9.6);
	Point	c;
	Point	point(5.3, 0.0);

	std::cout << "a.x: " << a.getX() << ", a.y: " << a.getY() << std::endl;
	std::cout << "b.x: " << b.getX() << ", b.y: " << b.getY() << std::endl;
	std::cout << "c.x: " << c.getX() << ", c.y: " << c.getY() << std::endl;
	std::cout << "point.x: " << point.getX() << ", point.y: " << point.getY() << std::endl;
	if (bsp(a, b, c, point))
	{
		std::cout << "Point belongs to abc triangle" << std::endl;
	}
	else
		std::cout << "Point does not belongs to abc triangle" << std::endl;
	return 0;
}
