#ifndef FIXED_HPP
# define FIXED_HPP

# pragma once
# include <iostream>
# include <cmath>

class Fixed
{
  public:
	Fixed();                          // constructeur par defaut
	Fixed(const Fixed &cpy);              // constructeur de recopie
	Fixed &operator=(const Fixed &other); // surcharge de l'operateur d'affectation (=)
	Fixed(const int intVal);              // constructeur qui convertit nbToFix en virgule fixe
	Fixed(const float floatVal);          // constructeur qui convertit nbToFix en virgule fixe
	~Fixed();                             // destructor

	int getRawBits(void) const;
	void setRawBits(int const rawBits);

	float	toFloat(void)const;           //convertit la valeur en virgule fixe en nombre à virgule flottante
	int		toInt(void)const;             //convertit la valeur en virgule fixe en nombre entier

  private:
	int _rawBits;                         //bits bruts du nb à virgule fixe
	static const int _fractionalBits = 8;     //bits fractionnaire du nb à virgule fixe
};

std::ostream	&operator<<(std::ostream &out, const Fixed &value);

#endif
