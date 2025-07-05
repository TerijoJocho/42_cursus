#include "AForm.hpp"
# include "../BureaucratClass/Bureaucrat.hpp"

AForm::AForm(std::string const name, int const gradeToSign, int const gradeToExecute)
		: _name(name), _gradeToSign(gradeToSign),
			_gradeToExecute(gradeToExecute), _isSigned(false)
{
	if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw AForm::GradeTooHighException();
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &other)
		: _name(other.getName()),
			_gradeToSign(other.getGradeToSign()),
			_gradeToExecute(other.getGradeToExecute()),
				_isSigned(false)
{
	if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw AForm::GradeTooHighException();
}

AForm &AForm::operator=(const AForm &other)
{
	(void)other;
	return *this;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Form exception: Grade is too high.");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Form exception: Grade is too Low.");
}

const char* AForm::FormSignedException::what() const throw()
{
	return ("Form exception: The form is not signed.");
}

std::string const AForm::getName() const
{
	return this->_name;
}

bool AForm::getIsSigned() const
{
	return this->_isSigned;
}

int AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &other)
{
	if (this->_isSigned)
		std::cout << "Form is already signed." << std::endl;
	else if (other.getGrade() <= this->getGradeToSign())
	{
		this->_isSigned = true;
		std::cout << "Bureaucrat " << other.getName() << " signed " << this->getName() << std::endl;
	}
	else
	{
		std::cout << other.getName() << " couldn't sign " << this->getName() << " because: ";
		throw AForm::GradeTooLowException();
	}
}

void AForm::checkExecutable(Bureaucrat const &executor) const
{
	std::cout << "Bureaucrat " << executor.getName() << " is trying to execute " << this->getName() << "." << std::endl;
	if (!this->getIsSigned())
		throw FormSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
}


std::ostream &operator<<(std::ostream &out, const AForm &other)
{
	return out << "Form's info: name: " << other.getName()
				<< ", grade to be signed: " << other.getGradeToSign()
				<< ", is signed: " << other.getIsSigned()
				<< ", grade to execute: " << other.getGradeToExecute() << std::endl;
}
