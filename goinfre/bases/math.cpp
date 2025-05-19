#include <cmath>
#include <iostream>

int	main(void)
{
	int	a = 0, b = 0;

	std::cout << "Donnez un nombre a:" << std::endl;
	std::cin >> a;
	std::cout << "Donnez un nombre b:" << std::endl;
	std::cin >> b;
	std::cout << a << " ^ " << b << " = " << pow(a, b) << std::endl;
	return (0);
}
