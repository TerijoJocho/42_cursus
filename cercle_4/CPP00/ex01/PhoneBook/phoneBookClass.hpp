/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBookClass.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:18:09 by terijo            #+#    #+#             */
/*   Updated: 2025/05/22 17:34:17 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "contactClass.hpp"

class phoneBook {
    public:
        phoneBook(void);
        ~phoneBook(void);    
    
        bool    ft_add_conact(std::string fN, std::string lN, std::string nn, std::string pN, std::string dS);
        bool    ft_search_contact(void)const;
        
    // private:

    //     int          index;

};

#endif