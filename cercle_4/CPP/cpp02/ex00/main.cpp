/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:18:18 by terijo            #+#    #+#             */
/*   Updated: 2025/06/05 16:02:37 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;    // creer un objet par default
	Fixed b(a); // creer un objet par copy
	Fixed c;    // creer un objet par default

	// attribut les valeurs de l'objet b à l'objet c
	// et renvoie une ref vers cette objet c
	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return (0);
}
