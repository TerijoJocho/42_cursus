#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
	std::cout << "FragTrap: " << this->_Name << " has been created." << std::endl;
}

FragTrap::FragTrap(const FragTrap &cpy) : ClapTrap(cpy)
{

}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		FragTrap::operator=(other);
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: " << this->_Name << " has been destroyed." << std::endl;
}

int	FragTrap::getHitPoints()
{
	return this->_HitPoints;
}
int	FragTrap::getAttackDamage()
{
	return this->_AttackDamage;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_Name << " has requested a HIGH-FIVE." << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->_EnergyPoints <= 0)
	{
		std::cout << "[ STATUS ] FragTrap " << this->_Name << " has no Energy points left." << std::endl;
		return ;
	}
	else if (this->_HitPoints <= 0)
	{
		std::cout << "[ STATUS ] FragTrap " << this->_Name << " is dead and cannot attack." << std::endl;
		return ;
	}
	std::cout << "\nFragTrap " << this->_Name << " attacks " << target << ", "
				<< "with his gun, causing " << this->_AttackDamage
				<< " points of damage !" << std::endl;
	this->_EnergyPoints--;
	std::cout << "[ STATUS ] FragTrap " << this->_Name
				<< ": remaining energy points: " << this->_EnergyPoints
				<< std::endl;
	return ;
}
