#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << this->getType() << " has been created." << std::endl;
}

Cure::~Cure()
{
		std::cout << this->getType() << " has been destroyed." << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	this->_type = other._type;
	std::cout << "cpy" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
		this->_type = other._type;
	}
	return (*this);
}

AMateria *Cure::clone() const
{
	AMateria*	ptr = new Cure();

	return (ptr);
}

void Cure::use(ICharacter &target)
{
	std::cout << "\'* heals " << target.getName() << "\'s wounds *\'" << std::endl;
}
