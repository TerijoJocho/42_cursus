/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 01:26:00 by terijo            #+#    #+#             */
/*   Updated: 2025/06/16 15:34:22 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact/contactClass.hpp"
#include "phoneBook/phoneBookClass.hpp"
#include <iostream>

int	main(void)
{
	int			flag = 0;
	std::string	input;
	phoneBook	repertoire;

	while (1)
	{
		std::cout << "Put a command (ADD, SEARCH, EXIT): ";
		getline(std::cin, input);
		if (std::cin.eof())
			return (1);
		if (input.empty() || input[0] == '\0' || input[0] == ' ')
		{
			std::cerr << "error: Missing arugment [ADD|SEARCH|EXIT]" << std::endl;
			continue ;
		}
		if (!strcmp(input.c_str(), "ADD"))
		{
			repertoire.addContact();
			flag = 1;
		}
		else if (!strcmp(input.c_str(), "SEARCH"))
		{
			if (flag != 1)
			{
				std::cout << "You need to ADD at least one contact first." << std::endl;
				continue ;
			}
			repertoire.ft_search_contact();
		}
		else if (!strcmp(input.c_str(), "EXIT"))
		{
			std::cout << "PhoneBook lost forever" << std::flush;
			break ;
		}
		else
			std::cerr << "error: Unknown command. Use: ADD, SEARCH or EXIT" << std::endl;
	}
	return (0);
}
