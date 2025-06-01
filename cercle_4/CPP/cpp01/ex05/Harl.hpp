/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:16:33 by terijo            #+#    #+#             */
/*   Updated: 2025/06/01 23:52:46 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#pragma once
#include <iostream>

class Harl
{
    private:
        void    debug(void) const;
        void    info(void) const;
        void    warning(void) const;
        void    error(void) const;
        
    public:
        Harl();
        ~Harl();
        void    complain(std::string level);
};

#endif