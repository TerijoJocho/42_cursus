#ifndef ANIMALCLASS_HPP
#define ANIMALCLASS_HPP

#pragma once

#include <iostream>
#include "../brainClass/brainClass.hpp"

class Animal
{
	public :
		Animal();
		virtual ~Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);

		virtual std::string		getType() const;
		virtual void			makeSound() const;

	protected:
		std::string	type;
};

#endif
