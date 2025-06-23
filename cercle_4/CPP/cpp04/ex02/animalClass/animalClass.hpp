#ifndef AANIMALCLASS_HPP
#define AANIMALCLASS_HPP

#pragma once

#include <iostream>
#include "../brainClass/brainClass.hpp"

class AAnimal
{
	public :
		AAnimal();
		virtual ~AAnimal();
		AAnimal(const AAnimal &other);
		AAnimal &operator=(const AAnimal &other);

		virtual std::string		getType() const;
		virtual void			makeSound() const = 0;

	protected:
		std::string	type;
};

#endif
