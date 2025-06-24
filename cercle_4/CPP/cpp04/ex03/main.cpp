#include "AMateriaClass/AMateria.hpp"
#include "MateriaClasses/Cure.hpp"
#include "MateriaClasses/Ice.hpp"

int main(void)
{
	{
		std::cout << "---First main---" << std::endl;
		AMateria*	a = new Cure();
		Cure		b;
		AMateria*	c = b.clone();

		std::cout << "\n\nType of cure: " << a->getType() << std::endl;
		std::cout << "Type of cureClone: " << c->getType() << "\n\n" << std::endl;

		AMateria*	d = new Ice();
		Ice		e;
		delete c;
		c = e.clone();

		std::cout << "\n\nType of ice: " << d->getType() << std::endl;
		std::cout << "Type of iceClone: " << c->getType() << "\n\n" << std::endl;

		delete a;
		delete c;
		delete d;
	}
	return (0);
}
