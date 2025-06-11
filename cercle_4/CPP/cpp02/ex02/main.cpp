/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:18:18 by terijo            #+#    #+#             */
/*   Updated: 2025/06/11 15:41:23 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed	a;
	Fixed	c;
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	Fixed const d(34.95f);

	std::cout << "For a :" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;

	std::cout << "\nFor c :" << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "--c: " << --c << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "c--: " << c-- << std::endl;
	std::cout << "c: " << c << std::endl;

	std::cout << "\nComparaison:" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "a < c ? : " << (a < c) << std::endl;
	std::cout << "a > c ? : " << (a > c) << std::endl;
	std::cout << "a <= c ? : " << (a <= c) << std::endl;
	std::cout << "a >= c ? : " << (a >= c) << std::endl;
	std::cout << "a == c ? : " << (a == c) << std::endl;
	std::cout << "a != c ? : " << (a != c) << std::endl;

	std::cout << "\nOperateurs arithmetique:" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "a + c : " << (a + c) << std::endl;
	std::cout << "a - c : " << (a - c) << std::endl;
	std::cout << "a * c : " << (a * c) << std::endl;//belek overflow invisible ; solution: staticcast int64(?)
	std::cout << "a / c : " << (a / c) << std::endl;

	std::cout << "\nFor a and c:" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "max: " << Fixed::max(a, c) << std::endl;
	std::cout << "min: " << Fixed::min(a, c) << std::endl;

	std::cout << "\nFor b and d:" << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "max: " << Fixed::maxConst(b, d) << std::endl;
	std::cout << "min: " << Fixed::minConst(b, d) << std::endl;

	std::cout << "\nCrash with a / 0 : " << std::endl;
	std::cout << (a / 0) << std::endl;

	return 0;
}
