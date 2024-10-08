#include <unistd.h>

void	put_nbr(int n)
{
	char	res;

	if (n >= 10)
		put_nbr(n / 10);
	res = n % 10 + '0';
	write(1, &res, 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		return (-1);
	res = 0;
	while (str[i])
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}

void	tab_mult(int nbr)
{
	int	i;
	int	res;

	i = 1;
	while (i <= 9)
	{
		put_nbr(i);
		write(1, " x ", 3);
		put_nbr(nbr);
		write(1, " = ", 3);
		res = i * nbr;
		put_nbr(res);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		tab_mult(ft_atoi(argv[1]));
	else
		write(1, "\n", 1);
	return (0);
}
