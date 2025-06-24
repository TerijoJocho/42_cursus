#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# pragma once
# include "../AMateriaClass/AMateria.hpp"
# include "../MateriaClasses/Cure.hpp"
# include "../MateriaClasses/Ice.hpp"

class ICharacter
{
  public:
	virtual -ICharacter(){};
	virtual std::string const &getName() const = 0;
	virtual void equip(AMateria *m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter &target) = 0;

  private:
	AMateria	*item[4];
	std::string const	_name;
};

#endif
