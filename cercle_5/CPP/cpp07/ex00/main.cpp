#include "whatever.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "---FIRST MAIN---" << std::endl;

		int	a = 0, b = 1;

		std::cout << "a: " << a << " b:" << b << std::endl;
		::swap<int>(a,b);
		std::cout << "a: " << a << " b:" << b << std::endl;

		std::cout << "min( a, b ) = " << ::min<int>( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max<int>( a, b ) << std::endl;
	}
	{
		std::cout << "\n\n---SUBJECT MAIN---" << std::endl;
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	return 0;
}
