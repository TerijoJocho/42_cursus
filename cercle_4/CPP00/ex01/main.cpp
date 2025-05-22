/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 01:26:00 by terijo            #+#    #+#             */
/*   Updated: 2025/05/22 18:15:16 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cctype>
#include "contactClass.hpp"
#include "phoneBookClass.hpp"

bool    ft_is_digit(std::string str)
{
    return (std::all_of(str.begin(), str.end(), ::isdigit));
}

void    ft_check_input(std::string &str, std::string const input)
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
        while (str.empty())
        {
            std::cout << input;
            getline(std::cin, str); 
        }
    }
    return ;
}

void    ft_add(phoneBook &repertoire)
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
    repertoire.ft_add_conact(firstName, lastName, nickname, phoneNumber, darkSecret);
}

int main(int argc, char **argv)
{
    phoneBook   repertoire;
    
    if (argc != 2)
    {
        std::cerr << "error: Missing arugment [ADD|SEARCH|EXIT]" << std::endl;
        return (1);
    }
    // while (1)
    // {
           if (!strcmp(argv[1], "ADD"))
                ft_add(repertoire);
            else if (!strcmp(argv[1], "SEARCH"))
                repertoire.ft_search_contact();
            else if (!strcmp(argv[1], "EXIT"))
            {
                std::cout << "PhoneBook lost for ever" << std::endl;        
                return (0);
            }
            else
                std::cerr << "error: Unknown command. Use: ADD, SEARCH or EXIT" << std::endl;        
            //     break ;
            // else
            //     continue ;
    // }
    return (0);
}