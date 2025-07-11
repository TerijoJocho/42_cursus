#include "Span.hpp"


int	main(void)
{
	{
		std::cout << "---EXCEPTION MAIN---" << std::endl;
		Span s(4);

		for (int i = 0; i < 5; i++)
		{
			try
			{
				s.addNumbers(i);
			}
			catch (const std::exception &e)
			{
				std::cerr << "Lenght error: " << e.what() << '\n';
			}
		}
	}

	{
		std::cout << "\n\n---EXCEPTION_2 MAIN---" << std::endl;
		Span s(0);

		for (int i = 0; i < 0; i++)
		{
			try
			{
				s.addNumbers(i);
			}
			catch (const std::exception &e)
			{
				std::cerr << "Lenght error: " << e.what() << '\n';
			}
		}
		try
		{
			std::cout << "Longest span: " << s.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "\n\n---EXCEPTION_3 MAIN---" << std::endl;
		Span s(1);

		for (int i = 0; i < 1; i++)
		{
			try
			{
				s.addNumbers(i);
			}
			catch (const std::exception &e)
			{
				std::cerr << "Lenght error: " << e.what() << '\n';
			}
		}
		try
		{
			std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
		{
		std::cout << "\n\n---LONGEST SPAN WITH N=10 MAIN---" << std::endl;
		Span s(10);

		for (int i = 0; i < 10; i++)
		{
			try
			{
				s.addNumbers(i);
			}
			catch (const std::exception &e)
			{
				std::cerr << "Lenght error: " << e.what() << '\n';
			}
		}
		try
		{
			std::cout << "Longest span: " << s.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "\n\n---SHORTEST SPAN WITH N=10 MAIN---" << std::endl;
		Span s(10);

		for (int i = 0; i < 10; i++)
		{
			try
			{
				s.addNumbers(i);
			}
			catch (const std::exception &e)
			{
				std::cerr << "Lenght error: " << e.what() << '\n';
			}
		}
		try
		{
			std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "\n\n---SHORTEST SPAN WITH N=10 000 MAIN---" << std::endl;
		Span s(10000);

		s.addLoop();
		try
		{
			std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "\n\n---LONGEST SPAN WITH N=10 000 MAIN---" << std::endl;
		Span s(10000);

		s.addLoop();
		try
		{
			std::cout << "Longest span: " << s.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "\n\n---LONGEST SPAN WITH N=20 000 MAIN---" << std::endl;
		Span s(20000);

		s.addLoop();
		try
		{
			std::cout << "Longest span: " << s.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "\n\n---SHORTEST SPAN WITH N=20 000 MAIN---" << std::endl;
		Span s(20000);

		s.addLoop();
		try
		{
			std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return (0);
}
