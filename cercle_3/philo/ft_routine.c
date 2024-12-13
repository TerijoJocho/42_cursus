/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:03:19 by daavril           #+#    #+#             */
/*   Updated: 2024/12/10 17:03:16 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *philo)
{
	ft_message("is thinking", philo, philo->id);
}

void	philo_sleep(t_philo *philo)
{
	ft_message("is sleeping", philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}

/*fonctionne mais data race*/
void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	ft_message("has taken a fork", philo, philo->id);
	pthread_mutex_lock(philo->l_fork);
	ft_message("has taken a fork", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->eating = 1;
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_message("is eating", philo, philo->id);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_lock(philo->meal_lock);
	philo->eating = 0;
	pthread_mutex_unlock(philo->meal_lock);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

/*fonctionne pas mais pas de data race*/
/*void	forks_order(t_philo *philo, pthread_mutex_t **first_fork,
		pthread_mutex_t **last_fork)
{
	if ((size_t)philo->r_fork < (size_t)philo->l_fork)
	{
		*first_fork = philo->r_fork;
		*last_fork = philo->l_fork;
	}
	else
	{
		*first_fork = philo->l_fork;
		*last_fork = philo->r_fork;
	}
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*last_fork;

	forks_order(philo, &first_fork, &last_fork);
	pthread_mutex_lock(first_fork);
	ft_message("has taken a fork", philo, philo->id);
	pthread_mutex_lock(last_fork);
	ft_message("has taken a fork", philo, philo->id);

	pthread_mutex_lock(philo->meal_lock);
	philo->eating = 1;
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_message("is eating", philo, philo->id);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_lock(philo->meal_lock);
	philo->eating = 0;
	pthread_mutex_unlock(philo->meal_lock);
	pthread_mutex_unlock(last_fork);
	pthread_mutex_unlock(first_fork);
}*/
