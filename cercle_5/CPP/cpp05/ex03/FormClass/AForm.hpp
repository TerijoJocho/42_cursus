#ifndef AFORM_HPP
# define AFORM_HPP

# pragma once
# include <iostream>

class Bureaucrat;

class AForm
{
  public:
	AForm(std::string const name, int const gradeToSign, int const gradeToExecute);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

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

	class FormSignedException : public std::exception
	{
		public:
		const char *what() const throw();
	};

	/*MEMBER FUNCTION*/
	void beSigned(const Bureaucrat &other);

	void checkExecutable(Bureaucrat const &executor) const;
	virtual bool execute(Bureaucrat const & executor) const = 0;

  private:
	std::string const _name;
	int const _gradeToSign;
	int const _gradeToExecute;
	bool _isSigned;
	AForm();
};

std::ostream &operator<<(std::ostream &out, const AForm &other);

#endif
