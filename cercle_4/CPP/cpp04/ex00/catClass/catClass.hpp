#ifndef CATCLASS_HPP
#define CATCLASS_HPP

#pragma once
#include "../animalClass/animalClass.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);

		std::string		getType() const;
		void			makeSound() const;

	private:
		std::string	_type;

};

#endif
