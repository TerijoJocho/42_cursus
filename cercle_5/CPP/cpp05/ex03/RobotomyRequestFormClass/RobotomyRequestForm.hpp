#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

# pragma once
# include <iostream>
#include "../FormClass/AForm.hpp"
class Bureaucrat;

class RobotomyRequestForm : public AForm
{
  public:
	RobotomyRequestForm(std::string const);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	std::string const getTarget() const;
	bool execute(Bureaucrat const & executor) const;

  private:
    std::string _target;
};

#endif
