# include "PresidentialPardonForm.hpp"
# include "../BureaucratClass/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
		: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::srand(std::time(0));
    //change la suite des nombres aleatoire de std::rand()
    //a time(NULL) comme "seed" car cette valeur change tout le temps
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
		: AForm(other)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	(void)other;
    AForm::operator=(other);
	return *this;
}

std::string const PresidentialPardonForm::getTarget() const
{
    return this->_target;
}

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    this->checkExecutable(executor);
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    return true;
}


