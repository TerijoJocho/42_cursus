#ifndef BRAINCLASS_HPP
# define BRAINCLASS_HPP

# pragma once
#include <iostream>

class Brain
{
  public:
	Brain();
	Brain(const Brain &cpy);
	Brain &operator=(const Brain &other);
	~Brain();

	std::string	getIdea(int index) const;
	void		setIdea(int index, const std::string &ideas);

	private:
		std::string	ideas[100];
};

#endif
