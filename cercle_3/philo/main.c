/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:22:24 by daavril           #+#    #+#             */
/*   Updated: 2024/12/10 16:58:27 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_program		program;
	t_philo			philo[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];
	int				i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		while (++i < argc)
		{
			if (parsing(argv[i]) == 1)
			{
				ft_error("Error\n");
				return (1);
			}
		}
		init_prog(&program, philo);
		init_fork(forks, ft_atoi(argv[1]));
		init_struct(argv, philo, forks, &program);
		init_thread(&program, forks);
		ft_destroy("", &program, forks);
	}
	else
		ft_error("Error\n");
	return (0);
}
