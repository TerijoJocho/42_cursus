#include <unistd.h>

void	ft_union(char *s1, char *s2)
{
	int i;
	char	hash[256] = {0};

	i = 0;
	while (s1[i])
	{
		hash[s1[i]] = 1;
		write(1, &s1[i], 1);
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (hash[s2[i]] == 0)
		{
			write(1, &s2[i], 1);
			hash[s2[i]] = 1;
		}
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	else
		write(1, "\n", 1);
	return (0);
}
