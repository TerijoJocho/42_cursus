/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:03:19 by daavril           #+#    #+#             */
/*   Updated: 2024/11/19 17:52:42 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *philo)
{
	ft_message("is thinking", philo, philo->id);
}

void	philo_sleep(t_philo *philo)
{
	ft_usleep(philo->time_to_sleep);
	ft_message("is sleeping", philo, philo->id);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	ft_message("has taken a fork", philo, philo->id);
	if (philo->number_of_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	ft_message("has taken a fork", philo, philo->id);
	philo->eating = 1;
	ft_message("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}


	/*----------VERIF----------*/
	// printf("\nphilo %d\n", philo->id);
	// printf("time to think %zu\n", philo->time_to_die);
	// printf("time to eat %zu\n", philo->time_to_eat);
	// printf("time to sleep %zu\n", philo->time_to_sleep);
	// printf("number_times_to_eat %d\n", philo->number_times_to_eat);
	// printf("start %zu\n", philo->start);
	// printf("last meal %zu\n", philo->last_meal);
	// printf("eating %d\n", philo->eating);
	// printf("meals eaten %d\n", philo->meals_eaten);
	// printf("dead %d\n", *(int *)philo->dead);
	/*--------------------------*/
