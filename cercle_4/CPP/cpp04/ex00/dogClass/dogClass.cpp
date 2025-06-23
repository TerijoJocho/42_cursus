#include "dogClass.hpp"

Dog::Dog() : _type("Dog")
{
	std::cout << "A " << this->_type << " has been adopted." << std::endl;
}

Dog::~Dog()
{
	std::cout << "A " << this->_type << " took its last breath." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), _type(other._type)
{
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		this->_type = other._type;
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
