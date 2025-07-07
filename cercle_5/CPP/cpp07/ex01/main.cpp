#include "iter.hpp"
#include <iostream>
#include <cstdio>
#include <string>

void	printString(std::string const &str)
{
	std::cout << str << std::endl;
}

void	printInt(int const &i)
{
	std::cout << i << std::endl;
}

int main()
{

	{
		std::cout << "---INT---" << std::endl;
		std::string str[] = {"bonjour ", "la", "famille"};

		::iter(str, 3, printString);
	}

	{
		std::cout << "---STRING---" << std::endl;
		int arr[3] = {1, 2, 3};
		::iter(arr, 3, printInt);
	}

	return 0;
}
