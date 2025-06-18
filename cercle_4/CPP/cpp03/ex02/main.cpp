#include "ClapTrapClass/ClapTrap.hpp"
#include "ScavTrapClass/ScavTrap.hpp"
#include "FragTrapClass/FragTrap.hpp"

int	main(void)
{
	std::cout << "---FIRST MAIN---" << std::endl;
	{
		ClapTrap	a("Georges");
		ScavTrap	b("Philip");
		FragTrap	c("Luis");

		a.attack("José");
		b.attack("José");
		c.attack("José");
		a.takeDamage(5);
		a.beRepaired(3);
		b.takeDamage(15);
		b.beRepaired(8);
		c.takeDamage(43);
		c.beRepaired(25);
		a.beRepaired(5);
		b.takeDamage(110);
		b.beRepaired(5);
		c.takeDamage(999);
		c.beRepaired(35);
		b.guardGate();
		c.highFivesGuys();
	}
	std::cout << "\n\n---SECOND MAIN---" << std::endl;
	{
		FragTrap	a("Peter");

		for (int i = 0; i < 100; i++)
			a.attack("Enemy");
		a.attack("OutOfEnergy");
		a.attack("another one");
		a.highFivesGuys();
	}
	return (0);
}
