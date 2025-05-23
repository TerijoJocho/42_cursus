/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 01:26:00 by terijo            #+#    #+#             */
/*   Updated: 2025/05/23 20:03:37 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact/contactClass.hpp"
#include "phoneBook/phoneBookClass.hpp"
#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
#include <fstream>

bool	ft_is_alpha(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isalpha(str[i]))
			return (false);
	}
	return (true);
}

bool	ft_is_digit(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

void	ft_check_input(std::string &str, std::string const input)
{
	getline(std::cin, str);
	if (input == "Phonenumber: ")
	{
		while (str.empty() || !ft_is_digit(str))
		{
			std::cout << input;
			getline(std::cin, str);
		}
	}
	else
	{
		while (str.empty() || !ft_is_alpha(str))
		{
			std::cout << input;
			getline(std::cin, str);
		}
	}
	return ;
}

void	ft_add(phoneBook &repertoire)
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkSecret;
	std::cout << "Firstname: ";
	ft_check_input(firstName, "Firstname: ");
	std::cout << "Lastname: ";
	ft_check_input(lastName, "Lastname: ");
	std::cout << "Nickname: ";
	ft_check_input(nickname, "Nickname: ");
	std::cout << "Phonenumber: ";
	ft_check_input(phoneNumber, "Phonenumber: ");
	std::cout << "Dark secret: ";
	ft_check_input(darkSecret, "Dark secret: ");
	repertoire.ft_add_contact(firstName, lastName, nickname, phoneNumber,
		darkSecret);
}

void	ft_search(phoneBook &repertoire)
{
	repertoire.ft_search_contact(repertoire);
	return ;
}

int	main(void)
{
	std::string	input;
	phoneBook	repertoire;

	while (1)
	{
		std::cout << "Put a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, input);
		if (input.empty() || input[0] == '\0' || input[0] == ' ')
		{
			std::cerr << "error: Missing arugment [ADD|SEARCH|EXIT]" << std::endl;
			continue ;
		}
		if (!strcmp(input.c_str(), "ADD"))
			ft_add(repertoire);
		else if (!strcmp(input.c_str(), "SEARCH"))
			ft_search(repertoire);
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
