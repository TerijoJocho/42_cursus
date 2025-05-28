/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBookClass.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:18:09 by terijo            #+#    #+#             */
/*   Updated: 2025/05/24 15:20:34 by terijo           ###   ########.fr       */
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
	void ft_search_contact(phoneBook &repertoire) const;

  private:
	int 	count;
	int		index;
	Contact contact[8];
};

#endif
