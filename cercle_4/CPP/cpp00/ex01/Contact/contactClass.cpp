/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contactClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 01:06:13 by terijo            #+#    #+#             */
/*   Updated: 2025/06/16 15:48:54 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contactClass.hpp"

Contact::Contact() : _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""),
	_darkSecret("")
{
	static std::ofstream log("info.log");
	std::clog.rdbuf(log.rdbuf());
	std::clog << "Default constructor contact called" << std::endl;
	return ;
}

Contact::Contact(std::string fN, std::string lN,
	std::string nn, std::string pN, std::string dS)
	: _firstName(fN), _lastName(lN), _nickname(nn), _phoneNumber(pN), _darkSecret(dS)
{
	std::clog << "Constructor Contact called" << std::endl;
}


Contact::~Contact(void)
{
	std::clog << "Destructor Contact called" << std::endl;
	return ;
}

std::string Contact::getFirstName() const
{
	return this->_firstName;
}
std::string Contact::getLastName()const
{
	return this->_lastName;
}

std::string Contact::getNickname()const
{
	return this->_nickname;
}

std::string Contact::getPhoneNumber()const
{
	return this->_phoneNumber;
}

std::string Contact::getDarkSecret()const
{
	return this->_darkSecret;
}
