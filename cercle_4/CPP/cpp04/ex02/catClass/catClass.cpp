#include "catClass.hpp"

Cat::Cat() : AAnimal(), _type("Cat")
{
	this->brainPtr = new Brain();
	std::cout << "A " << this->_type << " has been born." << std::endl;
}

Cat::~Cat()
{
	delete this->brainPtr;
	std::cout << "A " << this->_type << " took its last sleep." << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other), _type(other._type)
{
	this->brainPtr = new Brain(*other.brainPtr);
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		this->_type = other._type;
		if (this->brainPtr)
			delete this->brainPtr;
		this->brainPtr = new Brain(*other.brainPtr);
	}
	return (*this);
}

std::string		Cat::getType() const
{
	return (this->_type);
}

void	Cat::makeSound() const
{
	std::cout << this->_type << ": Miaou miaou, give me some food human !" << std::endl;
}

Brain*	Cat::getBrain() const
{
	return (this->brainPtr);
}
