/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:16:13 by terijo            #+#    #+#             */
/*   Updated: 2024/11/14 18:57:02 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct philo
{
    pthread_t   thread;
    int id;
    int number_of_philos;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int last_meal;
    
}              t_philo;


#endif