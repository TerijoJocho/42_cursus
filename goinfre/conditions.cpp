#include <iostream>
#include <string>

int	main(void)
{
	int	age = 0;

	std::cout << "Vous avez quel age ?" << std::endl;
	std::cin >> age;
	if (!age or age < 0)
		std::cout << "WTF" << std::endl;
	else if (age >= 1 and age < 18)
		std::cout << "AAAh t'es petit(e)" << std::endl;
	else
		std::cout << "AAAAAH t'es majeur en mode" << std::endl;
	return (0);
}
