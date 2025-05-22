/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBookClass.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:18:11 by terijo            #+#    #+#             */
/*   Updated: 2025/05/22 17:33:48 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "phoneBookClass.hpp"

phoneBook::phoneBook(void)
{
    std::clog << "Constructor phoneBook" << std::endl;
    return ;
}

phoneBook::~phoneBook(void)
{
    std::clog << "Destructor phoneBook" << std::endl;
    return ;
}

bool    phoneBook::ft_add_conact(std::string fN, std::string lN, std::string nn, std::string pN, std::string dS)
{
    Contact newContact(fN, lN, nn, pN, dS);
    std::clog << "Contact added: " << fN << std::endl;
    return(true);
}

bool    phoneBook::ft_search_contact(void)const
{
    return(false);
}
