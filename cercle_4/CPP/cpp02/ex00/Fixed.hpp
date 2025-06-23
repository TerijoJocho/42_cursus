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
	int _rawBits;                       //bits bruts du nb à virgule fixe
	static const int _fractionalBits = 8;   //bits fractionnaire du nb à virgule fixe
};
#endif
