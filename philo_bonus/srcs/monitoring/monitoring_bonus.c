/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:00:48 by ihadj             #+#    #+#             */
/*   Updated: 2025/08/13 13:01:07 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*death_watcher(void *ptr);

void	create_thread(t_philo *philo)
{
	pthread_t	thread;
	pthread_t	stop;

	if (pthread_create(&thread, NULL, monitoring, philo) != 0)
		clean_exit(philo, EXIT_FAILURE);
	pthread_detach(thread);
	if (pthread_create(&stop, NULL, death_watcher, philo) != 0)
		clean_exit(philo, EXIT_FAILURE);
	pthread_detach(stop);
}

void	*death_watcher(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	sem_wait(philo->data->death);
	clean_exit(philo, DEAD_CODE);
	return (NULL);
}

void	*monitoring(void *ptr)
{
	t_philo	*philo;
	size_t	time_since_meal;

	philo = (t_philo *)ptr;
	sem_wait(philo->data->write);
	philo->last_meal = philo->start_time;
	sem_post(philo->data->write);
	while (!simulation_ended(philo))
	{
		sem_wait(philo->data->write);
		time_since_meal = get_time() - philo->last_meal;
		sem_post(philo->data->write);
		if (time_since_meal >= philo->data->time_to_die)
		{
			sem_wait(philo->data->print_lock);
			sem_wait(philo->data->print);
			printf("%ld %d died\n", get_time() - philo->start_time, philo->id);
			sem_post(philo->data->print);
			sem_post(philo->data->death);
			break ;
		}
		usleep(100);
	}
	return (NULL);
}
