#include "BureaucratClass/Bureaucrat.hpp"
#include "FormClass/AForm.hpp"
#include "InternClass/Intern.hpp"
#include "PresidentialPardonFormClass/PresidentialPardonForm.hpp"
#include "RobotomyRequestFormClass/RobotomyRequestForm.hpp"
#include "ShrubberyCreationFormClass/ShrubberyCreationForm.hpp"

int	main(void)
{
	Intern	someRandomIntern;
	AForm	*rrf;

	std::cout << "----MAIN---" << std::endl;
	Bureaucrat Jhon("Jhon", 1);
	rrf = someRandomIntern.makeForm("robotomy reque", "Bender");
	if (!rrf)
	{
		std::cout<< "Form creation failed" << std::endl;
		return 1;
	}

	try
	{
		Jhon.signForm(*rrf);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
	try
	{
		Jhon.executeForm(*rrf);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}

	delete rrf;

	return (0);
}
