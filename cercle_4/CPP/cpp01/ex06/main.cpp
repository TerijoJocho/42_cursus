#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "error: choose one of them level: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return (1);
	}

	Harl		harl;
	std::string	level;

	level = argv[1];
	harl.complainFilter(level);
	return (0);
}
