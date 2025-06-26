#ifndef ICE_HPP
# define ICE_HPP

# pragma once
# include "../AMateriaClass/AMateria.hpp"
// #include "../CharacterClass/ICharacter.hpp"

class Ice : public AMateria
{
  public:
	Ice();
	Ice(const Ice &cpy);
	Ice &operator=(const Ice &other);
	~Ice();

	AMateria *clone() const;
	void use(ICharacter &target);

  private:
};

#endif
