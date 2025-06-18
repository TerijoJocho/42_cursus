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

FragTrap::FragTrap(const FragTrap &cpy)
{
	this->_AttackDamage = cpy._AttackDamage;
	this->_EnergyPoints = cpy._EnergyPoints;
	this->_HitPoints= cpy._HitPoints;
	this->_Name = cpy._Name;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		this->_AttackDamage = other._AttackDamage;
		this->_EnergyPoints = other._EnergyPoints;
		this->_HitPoints= other._HitPoints;
		this->_Name = other._Name;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: " << this->_Name << " has been destroyed." << std::endl;
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
