#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{

}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _Name(name)
{
	FragTrap	a("temp");
	ScavTrap	b("temp");

	this->_HitPoints = a.getHitPoints();
	this->_EnergyPoints = b.getEnergyPoints();
	this->_AttackDamage = a.getAttackDamage();
	std::cout << "DiamondTrap: " << this->_Name << " has been created." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: " << this->_Name << " has been destroyed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &cpy) : ClapTrap(cpy), ScavTrap(cpy), FragTrap(cpy), _Name(cpy._Name)
{

}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		this->_Name = other._Name;
	}
	return (*this);
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap says: \"Who am I ?\"\n" << this->_Name << " or " << ClapTrap::_Name << " ?" << std::endl;
}


