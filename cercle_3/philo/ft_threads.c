/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:28:58 by daavril           #+#    #+#             */
/*   Updated: 2024/11/22 17:51:48 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	int	dead_status;

	pthread_mutex_lock(philo->dead_lock);
	dead_status = *philo->dead;
	printf("dead_flag = %d of %d\n", *philo->dead, philo->id);
	pthread_mutex_unlock(philo->dead_lock);
	return (dead_status);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (is_dead(philo) == 0)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return NULL;
}

void	init_thread(t_program *prog, int philo_num)
{
	int	i;
	pthread_t	monitor;

	i = 0;
	if (pthread_create(&monitor, NULL, &monitor_routine, prog) != 0)
			ft_error("Error\n");
	while (i < philo_num)
	{
		if (pthread_create(&prog->philo[i].thread, NULL, &philo_routine, &prog->philo[i]) != 0)
			ft_error("Error\n");
		i++;
	}
	if (pthread_join(monitor, NULL) != 0)
			ft_error("Error\n");
	i = 0;
	while (i < philo_num)
	{
		if (pthread_join(prog->philo[i].thread, NULL) != 0)
			ft_error("Error\n");
		i++;
	}
}
