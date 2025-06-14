#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a("Georges");
	ClapTrap	c("Peter");
	std::string	b("Philip");

	a.attack(b);
	a.takeDamage(42);
	a.beRepaired(2);
	a.takeDamage(99);
	a.beRepaired(12);

	for (int i = 0; i < 10; i++)
		c.attack("Enemy");
	c.attack("OutOfEnergy");

	return (0);
}
