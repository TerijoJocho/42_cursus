#include "../PresidentialPardonFormClass/PresidentialPardonForm.hpp"
#include "../RobotomyRequestFormClass/RobotomyRequestForm.hpp"
#include "../ShrubberyCreationFormClass/ShrubberyCreationForm.hpp"
#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string form, std::string target) const
{
	std::string formList[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	int idx = -1;
	for (int i = 0; i < 3; i++)
	{
		if (form == formList[i])
		{
			idx = i;
			break ;
		}
	}

	switch (idx)
	{
	case 0:
		std::cout << "Intern creates " << form << std::endl;
		return (new ShrubberyCreationForm(target));
	case 1:
		std::cout << "Intern creates " << form << std::endl;
		return (new RobotomyRequestForm(target));
	case 2:
		std::cout << "Intern creates " << form << std::endl;
		return (new PresidentialPardonForm(target));
	default:
		std::cout << "Intern doesn't know the form " << form << std::endl;
		break ;
	}
	return (NULL);
}
