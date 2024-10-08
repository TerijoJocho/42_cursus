#include <stdlib.h>
#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	int	*array;
	int len;
	int	i;

	len = end - start;
	if (len < 0)
		len *=-1;
	len++;
	array = malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		if (start < end)
		{
			array[i] = end;
			end--;
			i++;
		}
		else
		{
			array[i] = end;
			end++;
			i++;
		}
	}
	return (array);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		int	*array;
		int	start = atoi(argv[1]);
		int	end = atoi(argv[2]);
		int	len = abs((end - start)) + 1;
		int	i = 0;

		array = ft_rrange(start, end);
		while (i < len)
		{
			printf("%d, ", array[i]);
			i++;
		}
	}
}
