#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*array;
	int	len;
	int	i;

	i = 0;
	len = end - start;
	if (len < 0)
		len *= -1;
	len++;
	//len = abs((end - start)) + 1;
	array = malloc(sizeof(int) * len);
	while (i < len)
	{
		if (start < end)
		{
			array[i] = start;
			start++;
			i++;
		}
		else
		{
			array[i] = start;
			start--;
			i++;
		}
	}
	return (array);
}
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	*array;
	int	i;
	int	start;
	int	end;
	int	len;

	if (argc == 3)
	{
		start = atoi(argv[1]);
		end = atoi(argv[2]);
		len = abs(end - start) + 1;

		array = ft_range(start, end);
		if (!array)
			return (1);

		// Affichage avec une boucle while
		i = 0;
		while (i < len)
		{
			printf("%d ", array[i]);
			i++;
		}
		printf("\n");

		free(array);
	}
	return (0);
}
