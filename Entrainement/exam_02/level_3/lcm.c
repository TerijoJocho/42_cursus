#include <stdio.h>

unsigned int	lcm(unsigned int x, unsigned int y)
{
	unsigned int	n;

	if (x == 0 || y == 0)
		return (0);
	if (x > y)
		n = x;
	else
		n = y;
	while (1)
	{
		if (n % x == 0 && n % y == 0)
			return (n);
		n++;
	}
}

int	main (void)
{
	unsigned int	x;
	unsigned int	y;

	x = 14;
	y = 5;
	printf("%d", lcm(x, y));
	return (0);
}
