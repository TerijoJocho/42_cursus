/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contactClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 01:06:13 by terijo            #+#    #+#             */
/*   Updated: 2025/05/22 01:53:47 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "contactClass.hpp"

Contact::Contact(std::string fN, std::string lN, std::string nn, std::string pN, std::string dS)
: firstName(fN),
    lastName(lN),
    nickname(nn),
    phoneNumber(pN),
    darkSecret(dS)
{
    std::cout << "Constructor" << std::endl;
    std::cout << this->firstName << std::endl;
    std::cout << this->lastName << std::endl;
    std::cout << this->nickname << std::endl;
    std::cout << this->phoneNumber << std::endl;
    std::cout << this->darkSecret << std::endl;

    return ;
}

Contact::~Contact(void)
{
    std::cout << "Destructor" << std::endl;
    return ;
}