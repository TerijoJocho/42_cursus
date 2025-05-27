/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contactClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 01:06:13 by terijo            #+#    #+#             */
/*   Updated: 2025/05/24 02:05:51 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contactClass.hpp"
#include <iostream>
#include <fstream>

Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""),
	darkSecret("")
{
	static std::ofstream log("info.log");
	std::clog.rdbuf(log.rdbuf());
	std::clog << "Default constructor contact called" << std::endl;
	return ;
}

Contact::Contact(std::string fN, std::string lN,
	std::string nn, std::string pN, std::string dS)
	: firstName(fN), lastName(lN), nickname(nn), phoneNumber(pN), darkSecret(dS)
{
	std::clog << "Constructor Contact called" << std::endl;
}


Contact::~Contact(void)
{
	std::clog << "Destructor Contact called" << std::endl;
	return ;
}
