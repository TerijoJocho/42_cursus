#include "iter.hpp"
#include <iostream>
#include <cstdio>
#include <string>

template <typename T> void print (const T &x)
{
	std::cout << x << std::endl;
}

void printDouble (double &x)
{
	std::cout << x << std::endl;
}

int main()
{

	{
		std::cout << "---STRING---" << std::endl;
		std::string str[] = {"bonjour ", "la", "famille"};

		::iter(str, 3, print<std::string>);
	}
	{
		std::cout << "---INT---" << std::endl;
		int arr[3] = {1, 2, 3};
		::iter(arr, 3, print<int>);
	}
	{
		std::cout << "---FLOAT---" << std::endl;
		float arr[3] = {1.0f, 2.45f, 3.31f};
		::iter<float>(arr, 3, print<float>);
	}
	{
		std::cout << "---CHAR---" << std::endl;
		char arr[3] = {'a', 'b', 'c'};
		::iter<char>(arr, 3, print<char>);
	}
	{
		std::cout << "---DOUBLE---" << std::endl;
		double arr[3] = {84.31, 654.532, 98452865489645328456.3512};
		::iter<double>(arr, 3, printDouble);
	}

	return 0;
}
