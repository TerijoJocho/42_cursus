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
	Fixed(const int nbToFix);             // constructeur qui convertit nbToFix en virgule fixe
	Fixed(const float nbToFix);           // constructeur qui convertit nbToFix en virgule fixe
	~Fixed();                             // destructor

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float	toFloat(void)const;          //convertit la valeur en virgule fixe en nombre à virgule flottante
	int		toInt(void)const;            //convertit la valeur en virgule fixe en nombre entier

  private:
	int _nbFixed;
	static const int _nbBits;
};

#endif
