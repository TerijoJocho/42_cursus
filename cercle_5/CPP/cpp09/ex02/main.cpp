#include "PmergeMe.hpp"



int	stringToInt(const std::string& str)
{
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



	std::string	input;
	std::queue<int>	queue;
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
				queue.push(stringToInt(token));
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
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
				queue.push(stringToInt(argv[i]));
			}
			catch (const std::exception& e)
			{
				std::cerr << "Error: " << e.what() <<  std::endl;
				return 1;
			}
		}
	}

	while (!queue.empty())
	{
		std::cout << queue.front() << " ";
		queue.pop();
	}

	PmergeMe	instance(input);
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
