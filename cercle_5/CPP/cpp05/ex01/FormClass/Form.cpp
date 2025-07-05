#include "Form.hpp"
# include "../BureaucratClass/Bureaucrat.hpp"

Form::Form(std::string const name, int const gradeToSign, int const gradeToExecute)
		: _name(name), _gradeToSign(gradeToSign),
			_gradeToExecute(gradeToExecute), _isSigned(false)
{
	if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw Form::GradeTooLowException();
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw Form::GradeTooHighException();
}

Form::~Form()
{
}

Form::Form(const Form &other)
		: _name(other.getName()),
			_gradeToSign(other.getGradeToSign()),
			_gradeToExecute(other.getGradeToExecute()),
				_isSigned(false)
{
	if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw Form::GradeTooLowException();
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw Form::GradeTooHighException();
}

Form &Form::operator=(const Form &other)
{
	(void)other;
	return *this;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form exception: Grade is too high.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form exception: Grade is too Low.");
}

std::string const Form::getName() const
{
	return this->_name;
}

bool Form::getIsSigned() const
{
	return this->_isSigned;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat &other)
{
	if (this->_isSigned)
		std::cout << "Form is already signed." << std::endl;
	else if (other.getGrade() <= this->getGradeToSign())
	{
		this->_isSigned = true;
		std::cout << other.getName() << " signed " << this->getName() << std::endl;
	}
	else
	{
		std::cout << other.getName() << " couldn't sign " << this->getName() << " because: ";
		throw Form::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &out, const Form &other)
{
	return out << "Form's info: name: " << other.getName()
				<< ", grade to be signed: " << other.getGradeToSign()
				<< ", is signed: " << other.getIsSigned()
				<< ", grade to execute: " << other.getGradeToExecute() << std::endl;
}
