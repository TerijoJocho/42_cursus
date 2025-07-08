#include <iostream>
#include "Array.hpp"

int main()
{
	int* a = new int();
	std::string* b  = new std::string();

	std::cout << *a << std::endl;
	std::cout << *b << std::endl;
	std::cout << b->length() << std::endl;

	Array<int> j(3);
	// Array<int> b(a);

	j[2];
	return 0;
}
