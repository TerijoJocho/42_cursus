/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:37:22 by daavril           #+#    #+#             */
/*   Updated: 2025/05/30 14:14:36 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"
#include "HumanA.h"
#include "HumanB.h"

int	main(void)
{
	Weapon	w1;

	w1.setType("Sword");
	std::string	typeRef = w1.getType();
	std::cout << typeRef << std::endl;
}
