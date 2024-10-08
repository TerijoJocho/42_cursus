#include <unistd.h>

int	ft_atoi(char *str)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	return (res);
}

int	is_prime(int nbr)
{
	int	i;

	if (nbr <= 1)
		return (0);
	i = 2;
	while (i * i <= nbr)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return(1);
}

void	put_nbr(int nbr)
{
	char	str_nbr;

	if (nbr >= 10)
		put_nbr(nbr / 10);
	str_nbr = nbr % 10 + '0';
	write(1, &str_nbr, 1);
}

void	add_prime_sum(char *str_nbr)
{
	int	nbr;
	int	sum;

	nbr = ft_atoi(str_nbr);
	sum = 0;
	while(nbr > 0)
	{
		if (is_prime(nbr))
			sum += nbr;
		nbr--;
	}
	put_nbr(sum);
	write(1, "\n", 1);
}

int	main (int argc, char **argv)
{
	if (argc == 2)
		add_prime_sum(argv[1]);
	else
		put_nbr('0');
}
