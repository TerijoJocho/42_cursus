#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "AMateria of type: " << this->_type << " has been created." << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria of type: " << this->_type << " has been destroyed." << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	this->_type = other._type;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}
