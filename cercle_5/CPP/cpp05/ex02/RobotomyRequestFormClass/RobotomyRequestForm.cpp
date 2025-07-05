# include "RobotomyRequestForm.hpp"
# include "../BureaucratClass/Bureaucrat.hpp"
# include <ctime>
# include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
		: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::srand(std::time(0));
    //change la suite des nombres aleatoire de std::rand()
    //a time(NULL) comme "seed" car cette valeur change tout le temps
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
		: AForm(other)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	(void)other;
    AForm::operator=(other);
	return *this;
}

std::string const RobotomyRequestForm::getTarget() const
{
    return this->_target;
}

bool RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    this->checkExecutable(executor);
    //rand() donne un nombre entre 0 et RAND_MAX
    //ici, nous donne soit 0 soit 1 avec une chance de ~50%
    int result = std::rand() % 2;

    if (!result)
    {
        std::cout << "The robotomy has failed." << std::endl;
        return false;
    }
 
    std::cout << this->getTarget() << " has been robotomyzed succesfully." << std::endl;
    return true;
}


