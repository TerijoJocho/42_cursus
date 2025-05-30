#include "HumanA.h"

HumanA::HumanA()
{

}

HumanA::~HumanA()
{

}

void	HumanA::attack(void) const
{
	std::cout << this->name << "attacks with"this->weapon.getType() << std::endl;
	return ;
}
