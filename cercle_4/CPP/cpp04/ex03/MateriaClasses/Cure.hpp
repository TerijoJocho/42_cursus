#ifndef CURE_HPP
# define CURE_HPP

# pragma once
# include "../AMateriaClass/AMateria.hpp"

class Cure : public AMateria
{
  public:
	Cure();
	Cure(const Cure &cpy);
	Cure &operator=(const Cure &other);
	~Cure();

	AMateria *clone() const;
	void use(ICharacter &target);

  private:

};

#endif
