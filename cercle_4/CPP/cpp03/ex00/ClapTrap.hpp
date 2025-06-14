#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# pragma once

#include <iostream>

class ClapTrap
{
  public:
	ClapTrap(std::string Name);
	~ClapTrap();

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

  private:
	std::string	_Name;
	int			_HitPoints;
	int			_EnergyPoints;
	int			_AttackDamage;
};

#endif
