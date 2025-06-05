#ifndef FIXED_HPP
# define FIXED_HPP

# pragma once
# include <iostream>

class Fixed
{
  public:
	Fixed(void);                          // constructeur par defaut
	Fixed(const Fixed &cpy);              // constructeur de recopie
	Fixed &operator=(const Fixed &other); // surcharge de l'operateur d'affectation (=)
	~Fixed();                             // destructor

	int getRawBits(void) const;
	void setRawBits(int const raw);

  private:
	int _nbFixed;
	static const int _nbBits;
};

#endif
