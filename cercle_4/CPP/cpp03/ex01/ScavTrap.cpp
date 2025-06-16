#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
    this->_AttackDamage = 20;
    this->_HitPoints = 100;
    this->_EnergyPoints = 50;
	std::cout << "ScavTrap: " << this->_Name << " has been created." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: " << this->_Name << " has been destroyed." << std::endl;
}

void    ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->_Name << " has entered Gate keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_EnergyPoints <= 0)
	{
		std::cout << "[ STATUS ] ScavTrap " << this->_Name 
					<< " has no Energy points left." 
					<< std::endl;
		return ;
	}
	else if (this->_HitPoints <= 0)
	{
		std::cout << "[ STATUS ] ScavTrap " << this->_Name 
					<< " is dead and cannot attack." 
					<< std::endl;
		return ;
	}
	std::cout << "\nScavTrap " << this->_Name
				<< " attacks " << target << ", "
				<< "with all his might, causing " << this->_AttackDamage << " points of damage !"
				<< std::endl;
	this->_EnergyPoints--;
	std::cout << "[ STATUS ] ScavTrap " << this->_Name 
				<< ": remaining energy points: " << this->_EnergyPoints 
				<< std::endl;
	return ;
}
