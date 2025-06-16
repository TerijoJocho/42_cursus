#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "---FIRST MAIN---" << std::endl;
	{
		ClapTrap	a("Georges");
		ScavTrap	b("Philip");

		a.attack("José");
		b.attack("José");
		a.takeDamage(5);
		a.beRepaired(3);
		b.takeDamage(15);
		b.beRepaired(8);
		a.beRepaired(5);
		b.takeDamage(110);
		b.beRepaired(5);
		b.guardGate();
	}
	std::cout << "\n\n---SECOND MAIN---" << std::endl;
	{
		ScavTrap	a("Peter");

		for (int i = 0; i < 50; i++)
			a.attack("Enemy");
		a.attack("OutOfEnergy");
		a.attack("another one");
		a.guardGate();
	}
	return (0);
}
