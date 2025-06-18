#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# pragma once
# include "../ClapTrapClass/ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
  public:
	ScavTrap(void);
	ScavTrap(std::string Name);
	ScavTrap(const ScavTrap &cpy);
	ScavTrap &operator=(const ScavTrap &other);
	~ScavTrap();

	int	getEnergyPoints();

	void attack(const std::string &target);
	void guardGate(void);
};

#endif
