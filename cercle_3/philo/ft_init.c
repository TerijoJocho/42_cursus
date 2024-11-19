/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:40:01 by daavril           #+#    #+#             */
/*   Updated: 2024/11/19 14:59:32 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_from_param(char **argv, t_philo *philo)
{
	philo->number_of_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		philo->number_times_to_eat = ft_atoi(argv[5]);
	else
		philo->number_times_to_eat = -1;
}

void	init_struct(char **argv, t_philo *philo, pthread_mutex_t *forks, t_program *prog)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philo[i].id = i + 1;
		init_from_param(argv, &philo[i]);
		philo[i].start = get_current_time();
		philo[i].last_meal = get_current_time();
		philo[i].eating = 0;
		philo[i].meals_eaten = 0;
		philo[i].dead = &prog->dead_flag;
		philo[i].l_fork = &forks[i];
		if (i == 0)
			philo[i].r_fork = &forks[philo[i].number_of_philos - 1];
		else
			philo[i].r_fork = &forks[i - 1];
		philo[i].write_lock = &prog->write_lock;
		philo[i].dead_lock = &prog->dead_lock;
		philo[i].meal_lock = &prog->meal_lock;
		i++;
	}
}

void	init_fork(pthread_mutex_t *forks, int philos_num)
{
	int	i;

	i = 0;
	while (i < philos_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_prog(t_program *prog, t_philo *philo)
{
	prog->dead_flag = 0;
	prog->philo = philo;
	pthread_mutex_init(&prog->dead_lock, NULL);
	pthread_mutex_init(&prog->meal_lock, NULL);
	pthread_mutex_init(&prog->write_lock, NULL);
}
