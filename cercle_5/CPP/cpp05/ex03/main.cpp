#include "BureaucratClass/Bureaucrat.hpp"
#include "FormClass/AForm.hpp"
#include "ShrubberyCreationFormClass/ShrubberyCreationForm.hpp"
#include "PresidentialPardonFormClass/PresidentialPardonForm.hpp"
#include "RobotomyRequestFormClass/RobotomyRequestForm.hpp"
#include "InternClass/Intern.hpp"

int main()
{
	{
		std::cout << "----FIRST MAIN---" << std::endl;
		
		Intern someRandomIntern;
		AForm* rrf;
		Bureaucrat	Jhon("Jhon", 1);

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		try 
		{
			Jhon.signForm(*rrf);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << "\n";
		}
		try 
		{
			rrf->execute(Jhon);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << "\n";
		}
	}
	{
		std::cout << "\n\n----SECOND MAIN---" << std::endl;

		
	}
	{
		std::cout << "\n\n----THIRD MAIN---" << std::endl;

	}

	return 0;
}
