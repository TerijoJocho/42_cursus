/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contactClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 01:06:13 by terijo            #+#    #+#             */
/*   Updated: 2025/05/22 17:35:14 by terijo           ###   ########.fr       */
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
    std::clog << "Constructor Contact called" << std::endl;
    return ;
}

Contact::~Contact(void)
{
    std::clog << "Destructor Contact called" << std::endl;
    return ;
}