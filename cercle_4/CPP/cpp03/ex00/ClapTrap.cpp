#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string Name) : _Name(Name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap: " << this->_Name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cpy)
{
	this->_AttackDamage = cpy._AttackDamage;
	this->_EnergyPoints = cpy._EnergyPoints;
	this->_HitPoints= cpy._HitPoints;
	this->_Name = cpy._Name;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
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

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: " << this->_Name << " has been destroyed." << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_EnergyPoints <= 0)
	{
		std::cout << "[ STATUS ] ClapTrap " << this->_Name
					<< " has no Energy points left."
					<< std::endl;
		return ;
	}
	else if (this->_HitPoints <= 0)
	{
		std::cout << "[ STATUS ] ClapTrap " << this->_Name
					<< " is dead and cannot attack."
					<< std::endl;
		return ;
	}
	std::cout << "\nClapTrap " << this->_Name
				<< " attacks " << target << ", "
				<< "causing " << this->_AttackDamage << " points of damage !"
				<< std::endl;
	this->_EnergyPoints--;
	std::cout << "[ STATUS ] ClapTrap " << this->_Name
				<< ": remaining energy points: " << this->_EnergyPoints
				<< std::endl;
	return ;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "\nClapTrap " << this->_Name
				<< " has taken " << amount
				<< " of damage."
				<< std::endl;

	this->_HitPoints -= amount;
	if (this->_HitPoints < 0)
		this->_HitPoints = 0;

	std::cout << "[ STATUS ] ClapTrap " << this->_Name
				<< " remaining hit points: " << this->_HitPoints
				<< std::endl;

	if (this->_HitPoints <= 0)
	{
		std::cout << "[ STATUS ] ClapTrap " << this->_Name << " is dead." << std::endl;
		return ;
	}
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_EnergyPoints <= 0)
	{
		std::cout << "[ STATUS ] ClapTrap " << this->_Name
					<< " has no Energy points left."
					<< std::endl;
		return ;
	}
	else if (this->_HitPoints <= 0)
	{
		std::cout << "[ STATUS ] ClapTrap " << this->_Name
					<< " is dead and cannot be repaired."
					<< std::endl;
		return ;
	}

	this->_HitPoints += amount;
	if (this->_HitPoints > 10)
		this->_HitPoints = 10;
	this->_EnergyPoints--;

	std::cout << "\nClapTrap " << this->_Name
				<< " repairs himself for " << amount << " hit points. "
				<< std::endl;
	std::cout << "[ STATUS ] ClapTrap " << this->_Name
				<< " remaining hit points: " << this->_HitPoints
				<< std::endl;
	std::cout << "[ STATUS ] ClapTrap " << this->_Name
				<< ": remaining energy points: " << this->_EnergyPoints
				<< std::endl;
	return ;
}
