/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:38:56 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/28 17:32:19 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	simulation_ended(t_philo *philo)
{
	bool	ended;

	pthread_mutex_lock(&philo->data->dead_mtx);
	ended = philo->data->end;
	pthread_mutex_unlock(&philo->data->dead_mtx);
	return (ended);
}

static void	day_loop(t_philo *philos)
{
	if (philos->data->philos_nb > 1 && philos->id % 2 != 0)
		ft_usleep(0.9 * philos->data->time_to_eat, philos);
	pthread_mutex_lock(&philos->read);
	if (philos->data->philos_nb == 1)
	{
		pthread_mutex_unlock(&philos->read);
		eat_alone(philos);
		return ;
	}
	pthread_mutex_unlock(&philos->read);
	while (!simulation_ended(philos))
	{
		if (simulation_ended(philos))
			break ;
		eat(philos);
		if (simulation_ended(philos))
			break ;
		nap(philos);
		if (simulation_ended(philos))
			break ;
		think(philos);
		if (philos->data->philos_nb == 3 || philos->data->philos_nb == 5)
			ft_usleep(0.5 * (philos->data->time_to_eat), philos);
	}
}

/*
	The cycle of EACH THREADS
	Make them start their cycle with a small/smart delay
*/
void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->data->start_mtx);
		pthread_mutex_lock(&philo->data->threads_set);
		if (philo->data->all_set == -42)
		{
			pthread_mutex_unlock(&philo->data->threads_set);
			pthread_mutex_unlock(&philo->data->start_mtx);
			return (NULL);
		}
		if (philo->data->start && philo->data->all_set)
		{
			pthread_mutex_unlock(&philo->data->threads_set);
			pthread_mutex_unlock(&philo->data->start_mtx);
			break ;
		}
		pthread_mutex_unlock(&philo->data->threads_set);
		pthread_mutex_unlock(&philo->data->start_mtx);
		usleep(50);
	}
	day_loop(philo);
	return (NULL);
}
