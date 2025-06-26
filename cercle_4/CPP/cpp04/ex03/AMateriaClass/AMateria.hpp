#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#pragma once
#include <iostream>
#include <string>
#include "../CharacterClass/ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria(std::string const &type);
		AMateria(const AMateria &cpy);
		AMateria &operator=(const AMateria &other);
		virtual ~AMateria();

		std::string const &getType() const; //returns the materia type

		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);

};

#endif
