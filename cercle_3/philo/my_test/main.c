/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:22:24 by daavril           #+#    #+#             */
/*   Updated: 2024/11/14 17:59:34 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <string.h>

int	mails = 0;
pthread_mutex_t	mutex;
struct timeval	current_time;

void	*routine(void *arg)
{
	char	*str;
	
	pthread_mutex_lock(&mutex);
	gettimeofday(&current_time, NULL);
	printf("Begin %s\n", arg);
	printf("Time in second: %ld and in micro second: %d\n", current_time.tv_sec, current_time.tv_usec);
	usleep(50000);
	if ((str = malloc(sizeof(char *) * 20)) == NULL)
	{
		free(str);
		return (printf("Error\n"), NULL);
	}
	strcpy(str, "This another test");
	printf("End of %s\n", arg);
	pthread_mutex_unlock(&mutex);
	pthread_exit(str); //not allowed
}

int	main(void)
{
	pthread_t	p1, p2;
	pthread_mutex_init(&mutex, NULL);
	void	*str;

	if (pthread_create(&p1, NULL, &routine, "thread 1") != 0)
		printf("Error\n");
	if (pthread_join(p1, &str) == 0)
		printf("Thread exited with '%s'\n", str);
	else
		printf("Error\n");
		
	if (pthread_create(&p2, NULL, &routine, "thread 2") != 0)
		printf("Error\n");
	if (pthread_join(p2, &str) == 0)
		printf("Thread exited with '%s'\n", str);
	else
		printf("Error\n");
	pthread_mutex_destroy(&mutex);
	return 0;
}

