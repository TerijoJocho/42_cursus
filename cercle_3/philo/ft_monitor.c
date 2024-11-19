/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:13:20 by daavril           #+#    #+#             */
/*   Updated: 2024/11/19 17:18:50 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_message(char *str, t_philo *philo, int id)
{
	size_t	time_spend;

	pthread_mutex_lock(philo->write_lock);
	time_spend = get_current_time() - philo->start;
	if (is_dead(philo) == 0)
		printf("%zu %d %s\n",time_spend, id, str);
	pthread_mutex_unlock(philo->write_lock);
}
