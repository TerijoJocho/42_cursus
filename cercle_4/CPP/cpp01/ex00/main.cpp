#include "Zombie.hpp"

int	main(void)
{
	Zombie	*p = newZombie("Jean");

	randomChump("Charles");//Charles meurt directement apres
	p->announce();
	delete p;//Jean meurt ici
	return (0);
}
