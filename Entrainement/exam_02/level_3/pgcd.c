#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		int	x = atoi(argv[1]);
		int	y = atoi(argv[2]);

		if (x<0 || y<0)
			return (0);
		while (x != y)
		{
			if (x > y)
				x -= y;
			else
				y -= x;
		}
		printf("%d", x);
	}
	printf("\n");
}
