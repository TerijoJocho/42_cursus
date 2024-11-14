/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:22:24 by daavril           #+#    #+#             */
/*   Updated: 2024/11/14 19:04:59 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char *str)
{
	printf("%s", str);
	/*free something here*/
	exit(EXIT_FAILURE);
}

void	create_philo(char *arg)
{
	t_philo	philo;
	
	philo.number_of_philos = 0;
	philo.id = 0;
}

void	init(char **argv)
{
	int	i;
	
	i = 0;
	
}

int	is_integer(char *str)
{
	long long	res;

	res = 0;
	if (*str == '-' || *str == '+')
			return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		res = res * 10 + (*str - '0');
		if (res >= 2147483648)
			return (0);
		str++;
	}
	return (1);
}

void	parsing(char *argv)
{
	if (!(is_integer(argv)))
		ft_error("One of the parameters is not an integer.\n");
}

int	main(int argc, char *argv[])
{
	int	i;
	
	i = 0;
	if (argc == 5 || argc == 6)
		while (++i < argc)
			parsing(argv[i]);
	else
		ft_error("The number of parameters is incorrect.\n");
	init(argv);
	return (0);
}
