/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBookClass.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:18:11 by terijo            #+#    #+#             */
/*   Updated: 2025/05/27 09:51:54 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBookClass.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

bool	ft_is_digit(std::string str);

phoneBook::phoneBook(void) : count(0), index(0)
{
	std::clog << "Constructor phoneBook" << std::endl;
	return ;
}

phoneBook::~phoneBook(void)
{
	std::clog << "Destructor phoneBook" << std::endl;
	return ;
}

std::string ft_truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

bool	ft_is_contact(char c)
{
	for (int i = 0; i < 8; i++)
	{
		if (c < 49 || c > 56)
			return (false);
	}
	return (true);
}

int	ft_str_to_int(std::string str)
{
	int	number;

	std::istringstream iss(str);
	iss >> number;
	return (number);
}

bool	ft_in_contact(std::string input, int contactNumber)
{
	for (int i = 0; i < contactNumber; i++)
	{
		if (ft_str_to_int(input) == i + 1)
			return (true);
	}
	return (false);
}

bool	ft_check_search_input(std::string input, int contactNumber)
{
	if (input.empty())
		return (false);
	else if (input.length() > 1 || !ft_is_contact(input[0])
		|| !ft_is_digit(input) || !ft_in_contact(input, contactNumber))
	{
		std::cout << "Please put a valid contact index...\n";
		return (false);
	}
	return (true);
}

std::string ft_get_contact(int contactNumber)
{
	std::string input;
	std::cout << "Choose a contact: ";
	getline(std::cin, input);
	while (!ft_check_search_input(input, contactNumber))
	{
		std::cout << "Choose a contact: ";
		getline(std::cin, input);
	}
	return (input);
}

bool phoneBook::ft_add_contact(std::string fN, std::string lN, std::string nn,
	std::string pN, std::string dS)
{
	this->contact[this->index] = Contact(fN, lN, nn, pN, dS);
	this->index = (this->index + 1) % 8;
	if (this->count < 8)
		this->count++;
	std::clog << "Contact added: " << fN << std::endl;
	return (true);
}

void phoneBook::ft_search_contact(phoneBook &repertoire) const
{
	(void)repertoire;
	std::string input;

	std::cout << "|" << std::setw(10) << "Index"
				<< "|" << std::setw(10) << "First name"
				<< "|" << std::setw(10) << "Last name"
				<< "|" << std::setw(10) << "Nickname"
				<< "|" << std::endl;
	for (int i = 0; i < this->count; i++)
	{
		std::cout << "|" << std::setw(10) << i
			+ 1 << "|" << std::setw(10) << ft_truncate(this->contact[i].firstName)
				<< "|" << std::setw(10) << ft_truncate(this->contact[i].lastName)
				<< "|" << std::setw(10) << ft_truncate(this->contact[i].nickname) << "|" << std::endl;
	}
	input = ft_get_contact(this->count);
	std::cout << this->contact[ft_str_to_int(input) - 1].firstName << std::endl;
	std::cout << this->contact[ft_str_to_int(input) - 1].lastName << std::endl;
	std::cout << this->contact[ft_str_to_int(input) - 1].nickname << std::endl;
	std::cout << this->contact[ft_str_to_int(input)- 1].phoneNumber << std::endl;
	std::cout << this->contact[ft_str_to_int(input) - 1].darkSecret << std::endl;
	return ;
}
