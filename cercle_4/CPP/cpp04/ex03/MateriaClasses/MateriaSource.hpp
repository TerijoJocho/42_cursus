#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# pragma once
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
  public:
	MateriaSource();
	MateriaSource(const MateriaSource &cpy);
	MateriaSource &operator=(const MateriaSource &other);
	~MateriaSource();

	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);

  private:
	AMateria *source[4];
};

#endif
