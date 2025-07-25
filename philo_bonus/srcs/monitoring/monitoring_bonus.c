/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:41:18 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/25 14:01:38 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	create_thread(t_philo *philo)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, monitoring, philo) != 0)
		exit(EXIT_FAILURE); //penser aussi a tout clear
	pthread_detach(thread);
}

void	*monitoring(void *ptr)
{
	t_philo	*philo;
	size_t	time_since_meal;

	philo = (t_philo *)ptr;
	philo->last_meal = philo->start_time;
	while (1)
	{
		time_since_meal = get_time() - philo->last_meal;
		if (time_since_meal >= philo->data->time_to_die)
		{
			if (sem_wait(philo->data->death) == 0)
			{
				sem_wait(philo->data->print);
				printf("%ld %d died\n", get_time() \
				- philo->start_time, philo->id);
				sem_post(philo->data->print);
			}
			exit(DEAD_CODE);
		}
		usleep(100);
	}
	return (NULL);
}

// printf(CR"%ld %d died\n"E, get_time() - philo->start_time, philo->id);