#include "WrongCatClass.hpp"

WrongCat::WrongCat() : WrongAnimal(), _type("WrongCat")
{
	std::cout << "A " << this->_type << " has been born." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "A " << this->_type << " took its last sleep." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other), _type(other._type)
{
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
		this->_type = other._type;
	}
	return (*this);
}

std::string		WrongCat::getType() const
{
	return (this->_type);
}


void	WrongCat::makeSound() const
{
	std::cout << this->_type << ": Miaou miaou, give me some food human !" << std::endl;
}
