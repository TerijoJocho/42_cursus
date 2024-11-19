/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:16:13 by terijo            #+#    #+#             */
/*   Updated: 2024/11/19 17:36:12 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define PHILO_MAX 300

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				number_of_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				number_times_to_eat;
	size_t			start;
	size_t			last_meal;
	int				eating;
	int				meals_eaten;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	test;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philo;
}					t_program;

// parsing
int					ft_atoi(const char *str);
void				parsing(char *argv);

// init
void				init_prog(t_program *prog, t_philo *philo);
void				init_struct(char **argv, t_philo *philo,
						pthread_mutex_t *forks, t_program *prog);
void				init_fork(pthread_mutex_t *forks, int philos_num);

// thread
void				init_thread(t_program *prog, int philo_num);
void				*philo_routine(void *arg);
void				*monitor_routine();
int	is_dead(t_philo *philo);

//routine
void	philo_think(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_eat(t_philo *philo);



//monitor
void	ft_message(char *str, t_philo *philo, int id);

// time
size_t				get_current_time(void);
int					ft_usleep(size_t millisecinds);

// end
void				ft_error(char *str);

#endif
