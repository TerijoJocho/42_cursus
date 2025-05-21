/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contactClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 00:55:53 by terijo            #+#    #+#             */
/*   Updated: 2025/05/22 01:45:51 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

#include <string>

class Contact {
    public:
        Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkSecret);
        ~Contact(void);    
    
        int          index;
        std::string  const firstName;
        std::string  const lastName;
        std::string  const nickname;
        std::string  const phoneNumber;
        std::string  const darkSecret;
        

};

#endif