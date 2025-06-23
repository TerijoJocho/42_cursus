#ifndef DOGCLASS_HPP
#define DOGCLASS_HPP

#pragma once
#include "../animalClass/animalClass.hpp"
#include "../brainClass/brainClass.hpp"

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);

		std::string		getType() const;
		void			makeSound() const;
		Brain*			getBrain() const;

	private:
		std::string	_type;
		Brain		*brainPtr;
};

#endif
