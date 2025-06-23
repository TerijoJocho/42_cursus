#include "catClass.hpp"

Cat::Cat() : Animal(), _type("Cat")
{
	std::cout << "A " << this->_type << " has been born." << std::endl;
}

Cat::~Cat()
{
	std::cout << "A " << this->_type << " took its last sleep." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), _type(other._type)
{
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		this->_type = other._type;
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
