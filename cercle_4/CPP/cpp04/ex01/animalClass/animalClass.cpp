#include "animalClass.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "An " << this->type << " has been created." << std::endl;
}

Animal::~Animal()
{
	std::cout << "An " << this->type << " has been destroyed." << std::endl;
}

Animal::Animal(const Animal &other)
{
	// std::cout << "Copy constructor" << std::endl;
	this->type = other.type;
}

Animal	&Animal::operator=(const Animal &other)
{
	// std::cout << "Operator=" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

std::string		Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << this->type <<": I am an animal." << std::endl;
}

