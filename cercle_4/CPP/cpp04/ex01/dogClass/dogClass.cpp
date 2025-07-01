#include "dogClass.hpp"

Dog::Dog() : Animal(), _type("Dog")
{
	this->brainPtr = new Brain();
	std::cout << "A " << this->_type << " has been adopted." << std::endl;
}

Dog::~Dog()
{
	delete this->brainPtr;
	std::cout << "A " << this->_type << " took its last breath." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), _type(other._type)
{
	this->brainPtr = new Brain(*other.brainPtr);
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		this->_type = other._type;
		if (this->brainPtr)
			delete this->brainPtr;
		this->brainPtr = new Brain(*other.brainPtr);
	}
	return (*this);
}

std::string		Dog::getType() const
{
	return (this->_type);
}

void	Dog::makeSound() const
{
	std::cout << this->_type << ": Waouf waouf, I am your best friend !" << std::endl;
}

Brain*	Dog::getBrain() const
{
	return (this->brainPtr);
}
