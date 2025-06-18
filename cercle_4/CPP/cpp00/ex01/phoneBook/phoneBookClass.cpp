/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBookClass.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:18:11 by terijo            #+#    #+#             */
/*   Updated: 2025/06/16 15:57:33 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBookClass.hpp"

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

/*----------------------ADD----------------------*/

void	phoneBook::setFirstName(std::string &str, const std::string input) const
{
	while (str.empty() || !isAlpha(str))
	{
		std::cout << input;
		getline(std::cin, str);
		if (std::cin.eof())
			return ;
	}
}

void	phoneBook::setLastName(std::string &str, const std::string input) const
{
	while (str.empty() || !isAlphaSpace(str))
	{
		std::cout << input;
		getline(std::cin, str);
		if (std::cin.eof())
			return ;
	}
}

void	phoneBook::setNickName(std::string &str, const std::string input) const
{
	while (str.empty() || !isAlphaPlus(str))
	{
		std::cout << input;
		getline(std::cin, str);
		if (std::cin.eof())
			return ;
	}
}

void	phoneBook::setPhoneNumber(std::string &str, const std::string input) const
{
	while (str.empty() || !isDigit(str))
	{
		std::cout << input;
		getline(std::cin, str);
		if (std::cin.eof())
			return ;
	}
}

void	phoneBook::setDarkSecret(std::string &str, const std::string input) const
{
	while (str.empty() || !isAlphaPlusWhitetSpace(str))
	{
		std::cout << input;
		getline(std::cin, str);
		if (std::cin.eof())
			return ;
	}
}

void	phoneBook::ft_check_input(std::string &str, const std::string input)
{
	getline(std::cin, str);
	if (std::cin.eof())
		return ;
	std::string	inputLevel[] = {"Firstname: ", "Lastname: ", "Nickname: ", "Phonenumber: ", "Dark secret: "};
	void (phoneBook::*functions[])(std::string &str, const std::string input) const = {&phoneBook::setFirstName, &phoneBook::setLastName, &phoneBook::setNickName, &phoneBook::setPhoneNumber, &phoneBook::setDarkSecret};
	for (int i = 0; i < 4; i++)
	{
		if (input == inputLevel[i])
		{
			(this->*functions[i])(str, input);
			return ;
		}
	}
	return ;
}

bool phoneBook::addToPhoneBook(std::string fN, std::string lN, std::string nn,
	std::string pN, std::string dS)
{
	this->contact[this->index] = Contact(fN, lN, nn, pN, dS);
	this->index = (this->index + 1) % 8;
	if (this->count < 8)
		this->count++;
	std::clog << "Contact added: " << fN << std::endl;
	return (true);
}

void	phoneBook::addContact()
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
	this->addToPhoneBook(firstName, lastName, nickname, phoneNumber,
		darkSecret);
}


/*----------------------SEARCH-----------------------------*/

std::string getContact(int contactNumber)
{
	std::string input;
	std::cout << "Choose a contact: ";
	getline(std::cin, input);
	if (std::cin.eof())
		return ("NULL");
	while (!checkSearchInput(input, contactNumber))
	{
		std::cout << "Choose a contact: ";
		getline(std::cin, input);
		if (std::cin.eof())
			return ("NULL");
	}
	return (input);
}

void phoneBook::ft_search_contact(void) const
{
	std::string input;

	std::cout << "|" << std::setw(10) << "Index"
				<< "|" << std::setw(10) << "First name"
				<< "|" << std::setw(10) << "Last name"
				<< "|" << std::setw(10) << "Nickname"
				<< "|" << std::endl;
	for (int i = 0; i < this->count; i++)
	{
		std::cout << "|" << std::setw(10) << i
			+ 1 << "|" << std::setw(10) << truncate(this->contact[i].getFirstName())
				<< "|" << std::setw(10) << truncate(this->contact[i].getLastName())
				<< "|" << std::setw(10) << truncate(this->contact[i].getNickname()) << "|" << std::endl;
	}
	input = getContact(this->count);
	if (input == "NULL")
		return ;
	std::cout << this->contact[strToInt(input) - 1].getFirstName() << std::endl;
	std::cout << this->contact[strToInt(input) - 1].getLastName() << std::endl;
	std::cout << this->contact[strToInt(input) - 1].getNickname() << std::endl;
	std::cout << this->contact[strToInt(input)- 1].getPhoneNumber() << std::endl;
	std::cout << this->contact[strToInt(input) - 1].getDarkSecret() << std::endl;
	return ;
}
