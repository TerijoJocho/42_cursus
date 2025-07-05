#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# pragma once
# include <iostream>
#include "../FormClass/AForm.hpp"
class Bureaucrat;

class PresidentialPardonForm : public AForm
{
  public:
	PresidentialPardonForm(std::string const);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	std::string const getTarget() const;
	bool execute(Bureaucrat const & executor) const;

  private:
    std::string _target;
};

#endif
