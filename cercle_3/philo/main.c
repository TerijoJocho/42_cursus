/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:22:24 by daavril           #+#    #+#             */
/*   Updated: 2024/11/22 15:49:08 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	init_thread(&program, ft_atoi(argv[1]));
	destroy_all(&program);
	// i = 0;
	// while (i <= program.philo[0].number_times_to_eat)
	// {
	// 	/*----------VERIF----------*/
	// 	printf("\nphilo %d\n", philo[i].id);
	// 	printf("time to think %zu\n", philo[i].time_to_die);
	// 	printf("time to eat %zu\n", philo[i].time_to_eat);
	// 	printf("time to sleep %zu\n", philo[i].time_to_sleep);
	// 	printf("number_times_to_eat %d\n", philo[i].number_times_to_eat);
	// 	printf("start %zu\n", philo[i].start);
	// 	printf("last meal %zu\n", philo[i].last_meal);
	// 	printf("eating %d\n", philo[i].eating);
	// 	printf("meals eaten %d\n", philo[i].meals_eaten);
	// 	printf("dead %d\n", *(int *)philo[i].dead);
	// 	/*--------------------------*/
	// 	i++;
	// }
	return (0);
}
