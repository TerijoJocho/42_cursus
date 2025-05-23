/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBookClass.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:18:09 by terijo            #+#    #+#             */
/*   Updated: 2025/05/23 19:11:28 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "contactClass.hpp"

class phoneBook
{
  public:
	phoneBook(void);
	~phoneBook(void);

	bool ft_add_contact(std::string fN, std::string lN, std::string nn,
		std::string pN, std::string dS);
	bool ft_search_contact(phoneBook &repertoire) const;

  private:
	int 	count;
	Contact contact[8];
};

#endif
