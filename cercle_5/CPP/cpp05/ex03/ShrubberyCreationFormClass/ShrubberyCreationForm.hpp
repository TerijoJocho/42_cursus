#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

# pragma once
# include <iostream>
#include "../FormClass/AForm.hpp"
class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
  public:
	ShrubberyCreationForm(std::string const);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();

	std::string const getTarget() const;
	bool execute(Bureaucrat const & executor) const;

  private:
    std::string _target;
};

#endif
