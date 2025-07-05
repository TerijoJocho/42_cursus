#ifndef FORM_HPP
# define FORM_HPP

# pragma once
# include <iostream>

class Bureaucrat;

class Form
{
  public:
	Form(std::string const name, int const gradeToSign, int const gradeToExecute);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	/*GETTER*/
	std::string const getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	/*EXCEPTION*/
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

	/*MEMBER FUNCTION*/
	void beSigned(const Bureaucrat &other);

  private:
	std::string const _name;
	int const _gradeToSign;
	int const _gradeToExecute;
	bool _isSigned;
	Form();
};

std::ostream &operator<<(std::ostream &out, const Form &other);

#endif
