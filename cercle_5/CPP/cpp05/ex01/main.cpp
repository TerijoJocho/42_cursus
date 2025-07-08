#include "BureaucratClass/Bureaucrat.hpp"
#include "FormClass/Form.hpp"

int main()
{
	{
		std::cout << "----FIRST MAIN---" << std::endl;
		try
		{
			Bureaucrat	a("Jhon", 230);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		try
		{
			Form	b("Luis", 0, 15);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n\n----SECOND MAIN---" << std::endl;

		Bureaucrat	a("Jhon", 45);
		Form		b("Bank", 25, 45);
		Form		c("Market", 63, 23);

		std::cout << a << std::endl;
		std::cout << b << c << std::endl;

		try
		{
			a.signForm(b);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for(int i = 45; i >= 25; i--)
		{
			a.gradeUp();
		}

		std::cout << "\n" << a << std::endl;

		try
		{
			a.signForm(b);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			a.signForm(c);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			a.signForm(c);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}
	{
		std::cout << "\n\n----THIRD MAIN---" << std::endl;

		try
		{
			Form	a("Carpet", 22, 450);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		try
		{
			Form	b("Seiling", 22, -4);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		Form	c("Shoes", 22, 45);

		try
		{
			Form	d(c);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		
		Form	d(c);

		std::cout << c << d << std::endl;

	}

	return 0;
}
