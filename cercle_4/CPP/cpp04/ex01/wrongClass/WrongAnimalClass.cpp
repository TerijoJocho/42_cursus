#include "WrongAnimalClass.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "An " << this->type << " has been created." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "An " << this->type << " has been destroyed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	// std::cout << "Copy constructor" << std::endl;
	this->type = other.type;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	// std::cout << "Operator=" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

std::string		WrongAnimal::getType() const
{
	return (this->type);
}


void	WrongAnimal::makeSound() const
{
	std::cout << this->type <<": I am an Wronganimal." << std::endl;
}
