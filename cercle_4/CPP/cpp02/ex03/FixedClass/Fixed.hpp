#ifndef FIXED_HPP
# define FIXED_HPP

# pragma once
# include <iostream>
# include <cmath>

class Fixed
{
  public:
	Fixed(void);                          // constructeur par defaut
	Fixed(const Fixed &cpy);              // constructeur de recopie
	Fixed &operator=(const Fixed &other); // surcharge de l'operateur d'affectation (=)
	Fixed(const int intVal);              // constructeur qui convertit nbToFix en virgule fixe
	Fixed(const float floatVal);          // constructeur qui convertit nbToFix en virgule fixe
	bool operator>(const Fixed &other) const; // surcharge de l'operateur (>)
	bool operator<(const Fixed &other) const; // surcharge de l'operateur (<)
	bool operator>=(const Fixed &other) const; // surcharge de l'operateur (>=)
	bool operator<=(const Fixed &other) const; // surcharge de l'operateur (<=)
	bool operator==(const Fixed &other) const; // surcharge de l'operateur (==)
	bool operator!=(const Fixed &other) const; // surcharge de l'operateur (!=)
	Fixed operator+(const Fixed &other) const; // surcharge de l'operateur (+)
	Fixed operator-(const Fixed &other) const; // surcharge de l'operateur (-)
	Fixed operator*(const Fixed &other) const; // surcharge de l'operateur (*)
	Fixed operator/(const Fixed &other) const; // surcharge de l'operateur (/)
	Fixed &operator++(void);              // surcharge de l'operateur (pre ++)
	Fixed operator++(int);               // surcharge de l'operateur (post ++)
	Fixed &operator--(void);              // surcharge de l'operateur (pre --)
	Fixed operator--(int);               // surcharge de l'operateur (post --)
	~Fixed();                             // destructor

	int getRawBits(void) const;           //getter
	void setRawBits(int const rawBits);   //setter

	float	toFloat(void)const;           //convertit la valeur en virgule fixe en nombre à virgule flottante
	int		toInt(void)const;             //convertit la valeur en virgule fixe en nombre entier

	static	Fixed &min(Fixed &first, Fixed &second);
	static	const Fixed &min(Fixed const &first, Fixed const &second);
	static	Fixed &max(Fixed &first, Fixed &second);
	static	const Fixed &max(Fixed const &first, Fixed const &second);

  private:
	int _rawBits;                         //bits bruts du nb à virgule fixe
	static const int _fractionalBits = 8;     //bits fractionnaire du nb à virgule fixe
};

std::ostream	&operator<<(std::ostream &out, const Fixed &value);

#endif
