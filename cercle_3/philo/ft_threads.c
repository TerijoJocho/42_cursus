/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:28:58 by daavril           #+#    #+#             */
/*   Updated: 2024/12/13 17:51:55 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	int	dead_status;

	pthread_mutex_lock(philo->dead_lock);
	dead_status = *philo->dead;
	pthread_mutex_unlock(philo->dead_lock);
	return (dead_status);
}

void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	ft_message("has taken a fork", philo, philo->id);
	ft_usleep(philo->time_to_die);
	pthread_mutex_unlock(philo->r_fork);
	return ;
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->number_of_philos == 1)
	{
		one_philo(philo);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (is_dead(philo) == 0)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

int	init_thread(t_program *prog, pthread_mutex_t *forks)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	if (pthread_create(&monitor, NULL, &monitor_routine, prog->philo) != 0)
		ft_destroy("Error\n", prog, forks);
	while (i < prog->philo[0].number_of_philos)
	{
		if (pthread_create(&prog->philo[i].thread, NULL, &philo_routine,
				&prog->philo[i]) != 0)
			return (printf("Error/n"), 1);
		i++;
	}
	if (pthread_join(monitor, NULL) != 0)
		return (printf("Error/n"), 1);
	i = 0;
	while (i < prog->philo[0].number_of_philos)
	{
		if (pthread_join(prog->philo[i].thread, NULL) != 0)
			return (printf("Error/n"), 1);
		i++;
	}
	return (0);
}
