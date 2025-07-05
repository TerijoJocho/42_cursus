#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# pragma once
# include <iostream>
#include "../FormClass/Form.hpp"

class Bureaucrat
{
  public:
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	int getGrade() const;
	std::string const &getName() const;

	void	gradeUp();
	void	gradeDown();

	void	signForm(Form &) const;

  private:
	int _grade;
	std::string const _name;
	Bureaucrat();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &someone);

#endif
