#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# pragma once

#include <iostream>

class ClapTrap
{
  public:
	ClapTrap();
	ClapTrap(std::string Name);
	ClapTrap(const ClapTrap &cpy);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

  protected:
	std::string	_Name;
	int			_HitPoints;
	int			_EnergyPoints;
	int			_AttackDamage;
};

#endif
