#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice has been created." << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice has been destroyed." << std::endl;
}

Ice::Ice(const Ice &cpy) : AMateria(cpy)
{

}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

AMateria *Ice::clone() const
{
	return (new Ice());
}

// void Ice::use(ICharacter &target)
// {
// 	std::cout << "\'* shoots an ice bolt at " << target.getName() << " *\'" << std::endl;
// }
