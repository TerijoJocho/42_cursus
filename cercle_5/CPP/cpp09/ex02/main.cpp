#include "PmergeMe.hpp"

int	stringToInt(const std::string& str)
{
	for(size_t i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ' && !isdigit(str[i]))
			throw std::runtime_error("Invalid number format 2");
	}
	std::stringstream	ss(str);
	int res;
	ss >> res;

	if (ss.fail() || res < 0)
		throw std::runtime_error("Invalid number format");

	return res;
}


int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: wrong number of argument." << std::endl;
		return 1;
	}


	PmergeMe	instance;

	std::string	input;
	/*if input is like this: "1 2 3 4 5"*/
	if (argc == 2)
	{
		input = argv[1];
		std::istringstream	iss(input);
		std::string			token;

		while (iss >> token)
		{
			try
			{
				instance.pushIntoQueue(stringToInt(token));
			}
			catch(const std::exception& e)
			{
				std::cerr << "Error: " << e.what() << '\n';
				return 1;
			}
		}

	}
	/*if input is like this: 1 2 3 4 5*/
	if (argc > 2)
	{
		for (int i = 1; i < argc; i++)
		{
			try
			{
				instance.pushIntoQueue(stringToInt(argv[i]));
			}
			catch (const std::exception& e)
			{
				std::cerr << "Error: " << e.what() <<  std::endl;
				return 1;
			}
		}
	}
	/*process merging*/
	try
	{
		instance.processInput();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() <<  std::endl;
	}

	return 0;
}
