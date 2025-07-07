#include "BaseClass/Base.hpp"

int	main(void)
{
	Base	a;
	Base*	empty = a.generator();

	std::cout << "By pointer: ";
	a.identify(empty);

	std::cout << "By reference: ";
	a.identify(*empty);

	delete empty;
	return (0);
}
