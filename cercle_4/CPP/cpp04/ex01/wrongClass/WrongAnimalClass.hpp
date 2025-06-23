#ifndef WRONGANIMALCLASS_HPP
#define WRONGANIMALCLASS_HPP

#pragma once

#include <iostream>

class WrongAnimal
{
	public :
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);

		virtual std::string		getType() const;
		void					makeSound() const;

	protected:
		std::string	type;
};

#endif
