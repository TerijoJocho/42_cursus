#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# pragma once

# include "contactClass.hpp"
# include <algorithm>
# include <cctype>
# include <cstring>
# include <fstream>
# include <iomanip>
# include <iostream>
# include <sstream>
# include <string>

class phoneBook
{
  public:
	phoneBook(void);
	~phoneBook(void);

	bool addToPhoneBook(std::string fN, std::string lN, std::string nn,
		std::string pN, std::string dS);
	void ft_search_contact(void) const;
	void addContact();

  private:
	int count;
	int index;
	Contact contact[8];
	void ft_check_input(std::string &str, const std::string input);
	void setFirstName(std::string &str, const std::string input) const;
	void setLastName(std::string &str, const std::string input) const;
	void setNickName(std::string &str, const std::string input) const;
	void setPhoneNumber(std::string &str, const std::string input) const;
	void setDarkSecret(std::string &str, const std::string input) const;
};

bool	isAlphaPlusWhitetSpace(const std::string &str);
bool	isAlphaPlus(const std::string &str);
bool	isAlphaSpace(const std::string &str);
bool	isAlpha(const std::string &str);
bool	isDigit(const std::string &str);

int		strToInt(std::string str);
bool	isInContact(std::string &input, int &contactNumber);
bool	checkSearchInput(std::string input, int contactNumber);
std::string truncate(std::string str);

#endif
