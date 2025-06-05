/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:14:57 by daavril           #+#    #+#             */
/*   Updated: 2025/06/03 17:31:57 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

int	main(void)
{
	Fixed	instance;
	Fixed	instanceCopy = instance;

	std::cout << "instance: " << instance.getRawBits() << std::endl;
	std::cout << "instanceCopy: " << instanceCopy.getRawBits() << std::endl;

	return (0);
}
