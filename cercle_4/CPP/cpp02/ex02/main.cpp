#include "Fixed.hpp"

int main( void )
{
	{
		std::cout << "FIRST MAIN" << std::endl;
		Fixed	a;
		Fixed	c;
		Fixed const	b(Fixed(5.05f) * Fixed(2));
		Fixed const d(34.95f);

		std::cout << "For a :" << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "++a: " << ++a << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "a++: " << a++ << std::endl;
		std::cout << "a: " << a << std::endl;

		std::cout << "\nFor c :" << std::endl;
		std::cout << "c: " << c << std::endl;
		std::cout << "--c: " << --c << std::endl;
		std::cout << "c: " << c << std::endl;
		std::cout << "c--: " << c-- << std::endl;
		std::cout << "c: " << c << std::endl;

		std::cout << "\nComparaison:" << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "c: " << c << std::endl;
		std::cout << "a < c ? : " << (a < c) << std::endl;
		std::cout << "a > c ? : " << (a > c) << std::endl;
		std::cout << "a <= c ? : " << (a <= c) << std::endl;
		std::cout << "a >= c ? : " << (a >= c) << std::endl;
		std::cout << "a == c ? : " << (a == c) << std::endl;
		std::cout << "a != c ? : " << (a != c) << std::endl;

		std::cout << "\nOperateurs arithmetique:" << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "c: " << c << std::endl;
		std::cout << "a + c : " << (a + c) << std::endl;
		std::cout << "a - c : " << (a - c) << std::endl;
		std::cout << "a * c : " << (a * c) << std::endl;
		std::cout << "a / c : " << (a / c) << std::endl;

		std::cout << "\nFor a and c:" << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "c: " << c << std::endl;
		std::cout << "max: " << Fixed::max(a, c) << std::endl;
		std::cout << "min: " << Fixed::min(a, c) << std::endl;

		std::cout << "\nFor b and d:" << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "d: " << d << std::endl;
		std::cout << "max: " << Fixed::max(b, d) << std::endl;
		std::cout << "min: " << Fixed::min(b, d) << std::endl;

		std::cout << "\nCrash with a / 0 : " << std::endl;
		// std::cout << (a / 0) << std::endl;
	}

	{
		std::cout << "\nSECOND MAIN" << std::endl;
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}

	return 0;
}
