#include "Bureaucrat.hpp"
#include <stdexcept>

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _grade(other._grade), _name(other._name)
{
	if (this->_grade < 1)
		throw GradeTooHighException();
	else if (this->_grade  > 150)
		throw GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other.getGrade() ;
		if (this->_grade < 1)
			throw GradeTooHighException();
		else if (this->_grade  > 150)
			throw GradeTooLowException();
	}
	return (*this);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::string const &Bureaucrat::getName() const
{
	return (this->_name);
}

void	Bureaucrat::gradeUp()
{
	if (this->getGrade() - 1 < 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::gradeDown()
{
	if (this->getGrade() + 1 > 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &someone)
{
	return out << someone.getName() << ", bureaucrat grade " << someone.getGrade() << std::endl;
}

void	Bureaucrat::signForm() const
{
	
}
