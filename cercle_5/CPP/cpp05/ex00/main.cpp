#include "Bureaucrat.hpp"

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
			Bureaucrat	b("Jean", 0);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
	}

	{
		std::cout << "----SECOND MAIN---" << std::endl;
		Bureaucrat	c("Luis", 5);

		std::cout << c << std::endl;
		c.gradeDown();
		std::cout << c << std::endl;
		for (int i = 0; i < 6; i++)
		{
			try
			{
				c.gradeUp();
			}
			catch(const std::exception& e)
			{
				std::cerr << "Exception: " << e.what() << std::endl;
			}
			std::cout << c << std::endl;
		}
		std::cout << "\n" << std::endl;
	}

	{
		std::cout << "----THIRD MAIN---" << std::endl;

		Bureaucrat	a("Paul", 150);
		Bureaucrat	b(a);
		Bureaucrat	c("Luis", 56);

		std::cout << a << b << c << std::endl;
		try
		{
			a.gradeDown();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		std::cout << a << b << c << std::endl;
		try
		{
			c = a;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		std::cout << a << b << c << std::endl;
	}

	return 0;
}
