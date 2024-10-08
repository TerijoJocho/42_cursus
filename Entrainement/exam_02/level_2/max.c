int	max(int *tab, unsigned int len)
{
	int	max;
	int i;

	max = 0;
	i = 0;
	if (len == 0)
		return (0);
	while (i < len)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}

#include <stdio.h>
#include<stdlib.h>

int	main(void)
{
	// int	tab[] = {2, 6, 9, 2, 3};
	int	*tab;
	int	m;

	m = max(tab, 5);
	printf("max=%d", m);
	return (0);
}
