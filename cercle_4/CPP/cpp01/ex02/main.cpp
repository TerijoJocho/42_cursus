/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:13:59 by daavril           #+#    #+#             */
/*   Updated: 2025/05/30 13:32:28 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";//variable
	std::string	*stringPTR = &str;//pointer to variable
	std::string	&stringREF = str;//reference to vriable

	std::cout << "Memory adress of the string variable: " << &str << std::endl;//adress of str
	std::cout << "Memory adress held by stringPTR: " << stringPTR << std::endl;//point to the adress of str
	std::cout << "Memory adress held by stringREF: " << &stringREF << std::endl;//has the same adress as str

	std::cout << "The value of the string variable :" << str << std::endl;//same
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;//value
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;//everywhere
	return (0);
}
