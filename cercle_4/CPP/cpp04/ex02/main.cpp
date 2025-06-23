#include "animalClass/animalClass.hpp"
#include "catClass/catClass.hpp"
#include "dogClass/dogClass.hpp"
#include "wrongClass/WrongAnimalClass.hpp"
#include "wrongClass/WrongCatClass.hpp"

int main(void)
{

	{
		std::cout << "---MY TEST---" << std::endl;

		AAnimal	*tab[10];
		for (int i = 0; i < 10; i++)
		{
			if (i < 5)
				tab[i] = new Dog();
			else
				tab[i] = new Cat();
		}
		std::cout << "\n" << std::endl;
		for (int i = 0; i < 10; i++)
		{
			delete tab[i];
		}
	}
	{
		std::cout << "\n\n---MY TEST V2---" << std::endl;
		Cat		cat;
		Cat		cpyCat;

		cat.getBrain()->setIdea(0, "FOOOOOOOD !!");
		std::cout << "Cat idea: " << cat.getBrain()->getIdea(0) << std::endl;
		cpyCat = cat;
		std::cout << "CopyCat idea: " << cpyCat.getBrain()->getIdea(0) << std::endl;
	}
	// {
	// 	std::cout << "\n\n---MY TEST V3---" << std::endl;
	// 	AAnimal b;

	// 	b.getType();
	// }
	{
		std::cout << "\n\n---SUBJECT TEST---" << std::endl;
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();

		delete j;//should not create a leak
		delete i;
	}
}
