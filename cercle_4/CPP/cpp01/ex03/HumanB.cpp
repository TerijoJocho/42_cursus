#include "HumanB.h"

HumanB::HumanB()
{
}

HumanB::HumanB(std::string name) : name(name)
{
	this->weaponPtr = NULL;
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weaponPtr = &weapon;
}

void HumanB::attack(void) const
{
	if (this->weaponPtr)
		std::cout << this->name << " attacks with their " << this->weaponPtr->getType() << std::endl;
	else
	{
		std::cout << "has no weapon" << std::endl;
	}
	return ;
}
