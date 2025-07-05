#include "BureaucratClass/Bureaucrat.hpp"
#include "FormClass/AForm.hpp"
#include "ShrubberyCreationFormClass/ShrubberyCreationForm.hpp"
#include "PresidentialPardonFormClass/PresidentialPardonForm.hpp"
#include "RobotomyRequestFormClass/RobotomyRequestForm.hpp"

int main()
{
	{
		std::cout << "----FIRST MAIN---" << std::endl;
		
		AForm* s = new ShrubberyCreationForm("home");
		Bureaucrat	a("Jhon", 1);

		try
		{
			s->execute(a);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			a.signForm(*s);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		try
		{
			a.executeForm(*s);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		delete s;
	}
	{
		std::cout << "\n\n----SECOND MAIN---" << std::endl;

		AForm* s = new RobotomyRequestForm("Someone");
		Bureaucrat	a("Jhon", 9);

		try
		{
			s->execute(a);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			a.signForm(*s);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		try
		{
			a.executeForm(*s);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		delete s;
	}
	{
		std::cout << "\n\n----THIRD MAIN---" << std::endl;

		AForm* s = new PresidentialPardonForm("CEO");
		Bureaucrat	a("Jhon", 1);

		try
		{
			s->execute(a);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			a.signForm(*s);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		try
		{
			a.executeForm(*s);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		delete s;
	}

	return 0;
}
