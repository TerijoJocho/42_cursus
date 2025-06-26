#include "Character.hpp"

Character::Character(std::string name) : _trashCount(0), _name(name)
{
	for(int i = 0; i < 4; i++)
	{
		this->_item[i] = NULL;
	}
	for(int i = 0; i < 100; i++)
	{
		this->_trash[i] = NULL;
	}
	std::cout << "Character [" << this->_name << "] appeared." << std::endl;
}

Character::~Character()
{
	for (int i = 0 ; i < 4; i++)
	{
		if (this->_item[i] != NULL)
			delete this->_item[i];
	}
	for (int i = 0 ; i < this->_trashCount; i++)
	{
		if (this->_trash[i] != NULL)
			delete this->_trash[i];
	}
	std::cout << "Character [" << this->_name << "] disappeared." << std::endl;
}

Character::Character(const Character &other) : _name(other._name)
{
	for(int i = 0; i < 4; i++)
	{
		if (other._item[i])
			this->_item[i] = other._item[i]->clone();
		else
			this->_item[i] = NULL;
	}
	for(int i = 0; i < 100; i++)
	{
		if (other._trash[i])
			this->_trash[i] = other._trash[i]->clone();
		else
			this->_trash[i] = NULL;
	}
}

Character &Character::operator=(const Character &other)
{
	if (this == &other)
		return (*this);

	for (int i = 0; i < 4; i++)
	{
		if (this->_item[i])
			delete this->_item[i];
		if (other._item[i])
			this->_item[i] = other._item[i]->clone();
		else
			this->_item[i] = NULL;
	}
	for (int i = 0; i < 100; i++)
	{
		if (this->_trash[i])
			delete this->_trash[i];
		if (other._trash[i])
			this->_trash[i] = other._trash[i]->clone();
		else
			this->_trash[i] = NULL;
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->_item[i] == NULL)
		{
			this->_item[i] = m;
			std::cout << "Character [" << this->getName() << "] has equiped materia " << m->getType() << " at inventory [" << i << "]" << "." << std::endl;
			return ;
		}
	}
	std::cout << this->getName() << " cannot equiped another materia because his inventory is full." << std::endl;
}

void Character::unequip(int idx)
{

	if (idx >= 0 && idx < 4 && this->_item[idx] != NULL)
	{
		if (this->_trashCount < 100)
			this->_trash[this->_trashCount++] = this->_item[idx];
		std::cout << "Character [" << this->getName() << "] has unequiped his " << this->_item[idx]->getType() << " materia at inventory [" << idx << "]" << "." << std::endl;
		this->_item[idx] = NULL;
		return ;
	}
	std::cout << this->getName() << " has nothing at inventory [" << idx << "]" << "." << std::endl;
}

void Character::use(int idx, ICharacter &target)
{

	if (idx >= 0 && idx < 4 && this->_item[idx] != NULL)
	{
		std::cout << this->getName() << " ";
		this->_item[idx]->use(target);
		return ;
	}
	std::cout << this->getName() << " has nothing at inventory [" << idx << "]" << "." << std::endl;
}
