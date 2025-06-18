#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# pragma once
#include "../ClapTrapClass/ClapTrap.hpp"

class FragTrap : public ClapTrap
{
  public:
	FragTrap(void);
	FragTrap(std::string Name);
	FragTrap(const FragTrap &cpy);
	FragTrap &operator=(const FragTrap &other);
	~FragTrap();

	void	attack(const std::string &target);
	void	highFivesGuys(void);
};

#endif
