#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# pragma once

#include "../ScavTrapClass/ScavTrap.hpp"
#include "../FragTrapClass/FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
  public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &cpy);
	DiamondTrap &operator=(const DiamondTrap &other);
	~DiamondTrap();

	void attack(const std::string &target);
	void whoAmI();

  private:
	std::string	_Name;
};

#endif
