#ifndef WRONGCATCLASS_HPP
#define WRONGCATCLASS_HPP

#pragma once
#include "WrongAnimalClass.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat &operator=(const WrongCat &other);

		std::string		getType() const;
		void			makeSound() const;

	private:
		std::string	_type;

};

#endif
