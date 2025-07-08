#include "../BureaucratClass/Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
			: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	(void)other;
	AForm::operator=(other);
	return (*this);
}

std::string const PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

bool PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	this->checkExecutable(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return (true);
}
