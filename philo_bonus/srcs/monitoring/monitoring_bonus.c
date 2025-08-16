/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:00:48 by ihadj             #+#    #+#             */
/*   Updated: 2025/08/16 17:34:09 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

pthread_t	create_thread(t_philo *philo)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, monitoring, philo) != 0)
		clean_exit(philo, EXIT_FAILURE);
	return (thread);
}

static int	monitor_detects(t_philo *philo)
{
	size_t	time_since_meal;

	sem_wait(philo->data->write);
	time_since_meal = get_time() - philo->last_meal;
	sem_post(philo->data->write);
	if (time_since_meal >= philo->data->time_to_die)
	{
		sem_wait(philo->data->print_lock);
		sem_wait(philo->data->print);
		printf("%ld %d died\n", get_time() - philo->start_time, philo->id);
		sem_post(philo->data->print);
		sem_wait(philo->data->write);
		philo->dead = true;
		sem_post(philo->data->write);
		return (1);
	}
	return (0);
}

void	*monitoring(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	sem_wait(philo->data->write);
	philo->last_meal = philo->start_time;
	sem_post(philo->data->write);
	while (!simulation_ended(philo))
	{
		if (monitor_detects(philo))
			break ;
		usleep(100);
	}
	return (NULL);
}
