#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
	{
		this->source[i] = NULL;
	}
	std::cout << "MateriaSource created." << std::endl;
}

MateriaSource::~MateriaSource()
{
	for(int i = 0; i < 4; i++)
	{
		delete this->source[i];
	}
	std::cout << "MateriaSource destroyed." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &cpy)
{
	(void)cpy;
	return ;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	(void)other;
	return(*this);
}

void MateriaSource::learnMateria(AMateria *toLearn)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->source[i] == NULL)
		{
			this->source[i] = toLearn;
			std::cout << "Materia " << toLearn->getType() << " learnt." << std::endl;
			return ;
		}
	}
	std::cout << "Cannot learn a new materia." << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	if (type.compare("ice"))
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->source[i]->getType().compare("ice"))
				return (this->source[i]->clone());
		}
	}
	else if (type.compare("cure"))
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->source[i]->getType().compare("cure"))
				return (this->source[i]->clone());
		}
	}
	return (NULL);
}
