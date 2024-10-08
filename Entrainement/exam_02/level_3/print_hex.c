#include <unistd.h>

int	ft_atoi(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}

void	print_hex(int x)
{
	char	base[] = "0123456789abcdef";

	if (x >= 16)
		print_hex(x / 16);
	x = x % 16;
	write(1, &base[x], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		print_hex(ft_atoi(argv[1]));
	}
	write(1, "\n", 1);
}
