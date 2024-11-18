/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:28:58 by daavril           #+#    #+#             */
/*   Updated: 2024/11/18 15:22:52 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	size_t	i;
	i = 0;
	while (i++ < 100000)
		philo->eating++;
	return NULL;
}

void	init_thread(t_philo *philo)
{
	pthread_t	thread;
	// pthread_mutex_t	r_fork;
	// pthread_mutex_t	l_fork;

	// pthread_mutex_init(&r_fork, NULL);
	// pthread_mutex_init(&l_fork, NULL);
	if (pthread_create(&thread, NULL, &routine, philo) != 0)
		ft_error("Error\n");
	if (pthread_join(thread, NULL) != 0)
		ft_error("Error\n");
	// pthread_mutex_destroy(&r_fork);
	// pthread_mutex_destroy(&l_fork);
}
