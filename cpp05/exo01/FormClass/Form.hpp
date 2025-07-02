#ifndef FORM_HPP
# define FORM_HPP

# pragma once
# include <iostream>
#include "../BureaucratClass/Bureaucrat.hpp"

class Form
{
  public:
	Form(std::string const name, int const gradeToSign, int const gradeToExecute);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	std::string const getName() const;
	bool getIsSigned() const;
	int const getGradeToSign() const;
	int const getGradeToExecute() const;

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	void beSigned(const Bureaucrat& other);

  private:
	std::string const _name;
	bool _isSigned;
	int const _gradeToSign;
	int const _gradeToExecute;
	Form();

};

std::ofstream &operator<<(std::ofstream &out, const Form &other);

#endif
