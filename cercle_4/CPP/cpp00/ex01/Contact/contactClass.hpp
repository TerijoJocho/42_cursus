/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contactClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 00:55:53 by terijo            #+#    #+#             */
/*   Updated: 2025/06/16 15:48:59 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#pragma once

# include <string>
#include <iostream>
#include <fstream>

class Contact
{
  public:
	Contact();
	Contact(std::string firstName, std::string lastName, std::string nickname,
		std::string phoneNumber, std::string darkSecret);
	~Contact(void);

	std::string getFirstName()const ;
	std::string getLastName()const ;
	std::string getNickname()const;
	std::string getPhoneNumber()const;
	std::string getDarkSecret()const;

  private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkSecret;
};

#endif
