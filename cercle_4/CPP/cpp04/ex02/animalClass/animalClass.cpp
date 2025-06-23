#include "animalClass.hpp"

AAnimal::AAnimal() : type("Animal")
{
	std::cout << "An " << this->type << " has been created." << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "An " << this->type << " has been destroyed." << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	// std::cout << "Copy constructor" << std::endl;
	this->type = other.type;
}

AAnimal	&AAnimal::operator=(const AAnimal &other)
{
	// std::cout << "Operator=" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

std::string		AAnimal::getType() const
{
	return (this->type);
}

void	AAnimal::makeSound() const
{
	std::cout << this->type <<": I am an animal." << std::endl;
}

