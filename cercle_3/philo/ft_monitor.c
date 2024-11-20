/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:13:20 by daavril           #+#    #+#             */
/*   Updated: 2024/11/20 17:26:28 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_message(char *str, t_philo *philo, int id)
{
	size_t	time_spend;

	pthread_mutex_lock(philo->write_lock);
	time_spend = get_current_time() - philo->start;
	if (is_dead(philo) == 0)
		printf("%zu %d %s\n", time_spend, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

int	philo_has_died(t_program *prog)
{
	int		i;
	size_t	current_time;

	i = 0;
	while (i < prog->philo[0].number_of_philos)
	{
		pthread_mutex_lock(prog->philo[i].meal_lock);
		current_time = get_current_time();
		if (prog->philo[i].eating == 0 && current_time
			- prog->philo[i].last_meal >= prog->philo[i].time_to_die)
		{
			pthread_mutex_lock(prog->philo[i].dead_lock);
			*prog->philo[i].dead = 1;
			pthread_mutex_unlock(prog->philo[i].dead_lock);
			ft_message("died", &prog->philo[i], prog->philo[i].id);
			pthread_mutex_unlock(prog->philo[i].meal_lock);
			return (1);
		}
		pthread_mutex_unlock(prog->philo[i].meal_lock);
		i++;
	}
	return (0);
}

int	philos_has_eaten(t_program *prog)
{
	int	i;

	i = 0;
	if (prog->philo[0].number_times_to_eat == -1)
		return (0);
	while (i < prog->philo[0].number_of_philos)
	{
		pthread_mutex_lock(prog->philo[i].meal_lock);
		if (prog->philo[i].number_times_to_eat > prog->philo[i].meals_eaten)
		{
			pthread_mutex_unlock(prog->philo[i].meal_lock);
			return (0);
		}
		pthread_mutex_unlock(prog->philo[i].meal_lock);
		i++;
	}
	pthread_mutex_lock(prog->philo[0].dead_lock);
	*prog->philo[0].dead = 1;
	pthread_mutex_unlock(prog->philo[0].dead_lock);
	return (1);
}

void	*monitor_routine(void *arg)
{
	t_program	*prog;

	prog = (t_program *)arg;
	while (1)
	{
		if (philo_has_died(prog) == 1 || philos_has_eaten(prog) == 1)
			break ;
		usleep(1000);
	}
	return (NULL);
}