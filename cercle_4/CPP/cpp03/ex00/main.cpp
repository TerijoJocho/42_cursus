#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "---FIRST MAIN---" << std::endl;
	{
		ClapTrap	a("Georges");
		std::string	b("Philip");

		a.attack(b);
		a.takeDamage(5);
		a.beRepaired(3);
		a.beRepaired(5);
		a.takeDamage(11);
	}
	std::cout << "---SECOND MAIN---" << std::endl;
	{
		ClapTrap	a("Peter");

		for (int i = 0; i < 10; i++)
			a.attack("Enemy");
		a.attack("OutOfEnergy");
		a.attack("another one");
	}
	return (0);
}
