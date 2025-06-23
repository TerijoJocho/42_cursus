#include "brainClass.hpp"

Brain::Brain()
{
	std::cout << "A brain has been created." << std::endl;
}

Brain::~Brain()
{
	std::cout << "A brain has exploded." << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

std::string	Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (this->ideas[index]);
	return ("");
}

void		Brain::setIdea(int index, const std::string &idea)
{
	if (index >=0 && index < 100)
		this->ideas[index] = idea;
	return ;
}

