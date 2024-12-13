/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:13:20 by daavril           #+#    #+#             */
/*   Updated: 2024/12/10 19:06:03 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_message(char *str, t_philo *philo, int id)
{
	size_t	time_spend;

	time_spend = get_current_time() - philo->start;
	pthread_mutex_lock(philo->write_lock);
	if (is_dead(philo) == 0)
		printf("%zu %d %s\n", time_spend, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

int	philos_has_eaten(t_philo *philo)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	if (philo[0].number_times_to_eat == -1)
		return (0);
	while (i < philo[0].number_of_philos)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].meals_eaten > philo[0].number_times_to_eat)
			total++;
		pthread_mutex_unlock(philo[i].meal_lock);
		i++;
	}
	if (total == philo[0].number_of_philos)
	{
		pthread_mutex_lock(philo[0].dead_lock);
		*philo->dead = 1;
		pthread_mutex_unlock(philo[0].dead_lock);
		return (1);
	}
	return (0);
}

int	philo_died(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if (philo->eating == 0 && get_current_time()
		- philo->last_meal >= philo->time_to_die)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	philo_has_died(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].number_of_philos)
	{
		if (philo_died(&philo[i]) == 1)
		{
			ft_message("died", &philo[i], philo[i].id);
			pthread_mutex_lock(philo[0].dead_lock);
			*philo[0].dead = 1;
			pthread_mutex_unlock(philo[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo_has_died(philo) == 1 || philos_has_eaten(philo) == 1)
			break ;
	}
	return (NULL);
}
