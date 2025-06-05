#ifndef FIXED_H
# define FIXED_H

# pragma once
# include <iostream>

class Fixed
{
  public:
	Fixed(void);             // default constructor
	// copy constructor,utile quand on veut creer un objet
	//qui a les meme parametre qu'un deja existant
	Fixed(const Fixed &cpy);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

  private:
	int _nbFixed;
	static const int _nbBits;
};

#endif
