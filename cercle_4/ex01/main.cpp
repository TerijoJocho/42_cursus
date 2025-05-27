/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 01:26:00 by terijo            #+#    #+#             */
/*   Updated: 2025/05/24 15:48:30 by terijo           ###   ########.fr       */
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

bool	ft_is_alpha_plus_wt_space(const std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if ((str[i] < 33 && str[i] > 126))
			return (false);
	}
	return (true);
}

bool	ft_is_alpha_plus(const std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if ((str[i] < 33 && str[i] > 126) || str[i] == ' ' || str[i] == '\t')
			return (false);
	}
	return (true);
}

bool	ft_is_alpha_space(const std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isalpha(str[i]) && str[i] != ' ')
			return (false);
	}
	return (true);
}

bool	ft_is_alpha(const std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isalpha(str[i]))
			return (false);
	}
	return (true);
}

bool	ft_is_digit(const std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

void	ft_check_input(std::string &str, const std::string input)
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
	else if (input == "Lastname: ")
	{
		while (str.empty() || !ft_is_alpha_space(str))
		{
			std::cout << input;
			getline(std::cin, str);
		}
	}
	else if (input == "Nickname: ")
	{
		while (str.empty() || !ft_is_alpha_plus(str))
		{
			std::cout << input;
			getline(std::cin, str);
		}
	}
	else if (input == "Dark secret: ")
	{
		while (str.empty() || !ft_is_alpha_plus_wt_space(str))
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

int	main(void)
{
	int			flag = 0;
	std::string	input;
	phoneBook	repertoire;

	while (1)
	{
		std::cout << "Put a command (ADD, SEARCH, EXIT): ";
		getline(std::cin, input);
		if (input.empty() || input[0] == '\0' || input[0] == ' ')
		{
			std::cerr << "error: Missing arugment [ADD|SEARCH|EXIT]" << std::endl;
			continue ;
		}
		if (!strcmp(input.c_str(), "ADD"))
		{
			ft_add(repertoire);
			flag = 1;
		}
		else if (!strcmp(input.c_str(), "SEARCH"))
		{
			if (flag != 1)
			{
				std::cout << "You need to ADD at least one contact first." << std::endl;
				continue ;
			}	
			repertoire.ft_search_contact(repertoire);
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
