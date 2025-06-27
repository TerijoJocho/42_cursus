#include "AMateriaClass/AMateria.hpp"
#include "MateriaClasses/Cure.hpp"
#include "MateriaClasses/Ice.hpp"
#include "CharacterClass/Character.hpp"
#include "MateriaClasses/MateriaSource.hpp"

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
	{
		std::cout << "\n\n---Second main---" << std::endl;
		AMateria*	ice = new Ice();
		AMateria*	iceClone = ice->clone();
		AMateria*	cure = new Cure();
		AMateria*	cureClone = cure->clone();
		AMateria*	ice2 = new Ice();
		AMateria*	ice2Clone = ice2->clone();
		Character	player("Jhon");
		Character	player2("Dylan");
		std::cout << "\n" << std::endl;
		player.unequip(0);
		player.use(4, player2);
		std::cout << "\n" << std::endl;
		player.equip(ice);
		player.equip(iceClone);
		player.equip(cure);
		player.equip(cureClone);
		player.equip(ice2);
		player2.equip(ice2Clone);
		std::cout << "\n" << std::endl;
		player2.use(2, player);
		player.use(1, player2);
		player2.use(0,player2);
		player.unequip(2);
		std::cout << "\n" << std::endl;

		delete ice2;
	}
	{
		std::cout << "\n\n---Third main---" << std::endl;
		IMateriaSource* src = new MateriaSource();
		std::cout << "\n" << std::endl;
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << "\n" << std::endl;
		ICharacter* me = new Character("me");
		AMateria* tmp;
		std::cout << "\n" << std::endl;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		std::cout << "\n" << std::endl;
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << "\n" << std::endl;
		delete bob;
		delete me;
		delete src;

	}
	return (0);
}
