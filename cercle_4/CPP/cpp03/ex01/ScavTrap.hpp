#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap(std::string Name);
    ~ScavTrap();

	void	attack(const std::string &target);
    void    guardGate(void);
};

#endif