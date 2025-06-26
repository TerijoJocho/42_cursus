#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# pragma once
# include "ICharacter.hpp"
#include "../AMateriaClass/AMateria.hpp"

class Character : public ICharacter
{
  public:
	Character(std::string name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character();

	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

  private:
	AMateria* _item[4];
	AMateria* _trash[100];
	int _trashCount;
	std::string const _name;
};

#endif
