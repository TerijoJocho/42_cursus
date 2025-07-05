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
	return ("Bureaucrat exception: Grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat exception: Grade is too low.");
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
	std::cout << this->getName() << " is trying to upgrade his grade." << std::endl;
	if (this->getGrade() - 1 < 1)
	{
		std::cout << this->getName() << " didn't manage to upgrade his grade because: ";
		throw GradeTooHighException();
	}
	else
	{
		this->_grade--;
		std::cout << this->getName() << " manage to upgrade his grade ; grade: " << this->getGrade() << std::endl;
	}
}

void	Bureaucrat::gradeDown()
{
	std::cout << this->getName() << " is trying to downgrade his grade." << std::endl;
	if (this->getGrade() + 1 > 150)
	{
		std::cout << this->getName() << " didn't manage to downgrade his grade because: ";
		throw GradeTooLowException();
	}
	else
	{
		this->_grade++;
		std::cout << this->getName() << " manage to downgrade his grade ; grade: " << this->getGrade() << std::endl;
	}
}

void	Bureaucrat::signForm(AForm& other) const
{
	std::cout << "Bureaucrat " << this->getName() << " is trying to sign " << other.getName() << "." << std::endl;
	other.beSigned(*this);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &someone)
{
	return out << someone.getName() << ", bureaucrat grade " << someone.getGrade() << std::endl;
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	if (form.execute(*this))
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	else
		std::cout << this->getName() << " failed to execute " << form.getName() << std::endl;
}

