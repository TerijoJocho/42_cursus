#include "Base.hpp"
#include "../EmptyClasses/A.hpp"
#include "../EmptyClasses/B.hpp"
#include "../EmptyClasses/C.hpp"
#include <cstdlib>
#include <ctime>

Base::~Base()
{
}

Base *Base::generator(void)
{
	static bool	seed = false;
	if (!seed)
	{
		std::srand(std::time(0));
		seed = true;
	}

	int	result;
	result = std::rand() % 3;

	switch (result)
	{
	case 0:
		return new A;
	case 1:
		return new B;
	case 2:
		// std::cout << result << std::endl;
		return new C;
	default:
		break;
	}
	return NULL;
}

void Base::identify(Base* p)
{
	/*TRY A*/
	A	*a = dynamic_cast<A *>(p);
	if (a)
		std::cout << "A" << std::endl;

	/*TRY B*/
	B	*b = dynamic_cast<B *>(p);
	if (b)
		std::cout << "B" << std::endl;

	/*TRY C*/
	C	*c = dynamic_cast<C *>(p);
	if (c)
		std::cout << "C" << std::endl;
}

void Base::identify(Base& p)
{
	/*TRY A*/
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch(const std::exception& e)
	{
		(void)e;
		// std::cerr << e.what() << '\n';
	}
	/*TRY B*/
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;
	}
	catch(const std::exception& e)
	{
		(void)e;
		// std::cerr << e.what() << '\n';
	}
	/*TRY C*/
	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)c;
	}
	catch(const std::exception& e)
	{
		(void)e;
		// std::cerr << e.what() << '\n';
	}
}
