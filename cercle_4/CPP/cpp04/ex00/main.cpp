#include "animalClass/animalClass.hpp"
#include "catClass/catClass.hpp"
#include "dogClass/dogClass.hpp"
#include "wrongClass/WrongAnimalClass.hpp"
#include "wrongClass/WrongCatClass.hpp"

int main(void)
{

	{
		std::cout << "---MY TEST---" << std::endl;
		Animal	a;
		Animal	*b = new Cat;
		Dog		c;

		a.makeSound();
		b->makeSound();
		c.makeSound();
		delete b;
	}
	{
		std::cout << "\n\n---SUBJECT TEST---" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		const WrongAnimal* k = new WrongCat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << k->getType() << " " << std::endl;

		k->makeSound(); //will output the wrongAnimal sound!
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
		delete k;
	}
}
