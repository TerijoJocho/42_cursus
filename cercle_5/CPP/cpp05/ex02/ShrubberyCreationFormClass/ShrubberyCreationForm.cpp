#include "ShrubberyCreationForm.hpp"
# include "../BureaucratClass/Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
		: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
		: AForm(other)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	(void)other;
    AForm::operator=(other);
	return *this;
}

std::string const ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}

bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    this->checkExecutable(executor);
    std::ofstream out(this->getTarget() + "_shrubbery");

    for (int i = 0; i < 5; i++)
    {
        for (int i = 0; i < 5; i++)
        {
            int spaces = 5 - i - 1;
            int c = i * 2 + 1;
    
            out << std::string(spaces, ' ');
            out << std::string(c, '%') << std::endl;
        }
        out << std::string(4, ' ') << '|' << std::endl;
    }
    out.close();
    return true;
}


