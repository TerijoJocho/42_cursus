#include "easyfind.hpp"
#include <vector>
#include <iostream>

int	main(void)
{
	std::vector<int>	v;

	for (int i = 0; i < 5; i++)
	{
		v.push_back(i);
	}
	try
	{
		std::vector<int>::iterator	it = easyfind(v, 3);
		(void)it;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	std::cout << "Found" << std::endl;

	try
	{
		std::vector<int>::iterator	it = easyfind(v, 85);
		(void)it;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	std::cout << "Found" << std::endl;
	return 0;
}
