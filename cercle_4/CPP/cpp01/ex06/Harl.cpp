#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void) const
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) const
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) const
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for ears, whereas you started working here just last month" << std::endl;
}

void Harl::error(void) const
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complainFilter(std::string level)
{
	int	lvl;

	lvl = -1;
	// tableau de string
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			lvl = i;
			break ;
		}
	}
	// switch case en "falltrough" = sans break ;
	switch (lvl)
	{
	case 0:
		this->debug();
	case 1:
		this->info();
	case 2:
		this->warning();
	case 3:
		this->error();
		break ;
	default:
		std::cout << "[ Some other complains... ]" << std::endl; //"catch-all" pour les cas inattendus
	}
	return ;
}
