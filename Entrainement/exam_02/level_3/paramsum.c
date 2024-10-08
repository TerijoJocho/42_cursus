#include <unistd.h>

void	put_nbr(int x)
{
	char	s;

	if (x >= 10)
		put_nbr(x / 10);
	s = (x % 10) + '0';
	write(1, &s, 1);
}

int	main(int argc, char **argv)
{
	(void)argv;

	put_nbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}
