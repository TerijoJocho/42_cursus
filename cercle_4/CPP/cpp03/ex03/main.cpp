#include "ClapTrapClass/ClapTrap.hpp"
#include "ScavTrapClass/ScavTrap.hpp"
#include "FragTrapClass/FragTrap.hpp"
#include "DiamondTrapClass/DiamondTrap.hpp"

int	main(void)
{
	ClapTrap	a("Mother");
	ScavTrap	b("Daughter");
	FragTrap	c("Male");
	DiamondTrap	d("Kid");

	a.attack("Jose");
	b.attack("Jose");
	c.attack("Jose");
	d.attack("Jose");

	a.takeDamage(42);
	b.takeDamage(41);
	c.takeDamage(40);
	d.takeDamage(41);

	a.beRepaired(12);
	b.beRepaired(12);
	c.beRepaired(12);
	d.beRepaired(12);

	d.whoAmI();
	return (0);
}
