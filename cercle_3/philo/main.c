/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:22:24 by daavril           #+#    #+#             */
/*   Updated: 2024/11/18 15:22:56 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char *str)
{
	printf("%s", str);
	/*free something here*/
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_program		program;
	t_philo			philo[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];
	int				i;

	i = 0;
	if (argc == 5 || argc == 6)
		while (++i < argc)
			parsing(argv[i]);
	else
		ft_error("The number of parameters is incorrect.\n");
	init_prog(&program, philo);
	init_fork(forks, ft_atoi(argv[1]));
	init_struct(argv, philo, forks, &program);
	printf("eating %d\n", philo[1].eating);
	return (0);
}
