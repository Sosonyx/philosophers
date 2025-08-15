/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:41:18 by ihadj             #+#    #+#             */
/*   Updated: 2025/08/15 15:02:48 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_threads(t_philo *philos)
{
	size_t	i;

	i = -1;
	while (++i < philos->data->philos_nb)
	{
		if (pthread_create(&philos[i].thread, NULL, &routine,
				&philos[i]) != 0)
			return (philos->data->all_set = -42, error_exit(philos, i), 0);
	}
	pthread_mutex_lock(&philos->data->threads_set);
	philos->data->all_set = 1;
	pthread_mutex_unlock(&philos->data->threads_set);
	return (1);
}

int	is_dead(t_philo *philo)
{
	size_t	time_since_meal;

	pthread_mutex_lock(&philo->read);
	time_since_meal = get_time() - philo->last_meal;
	pthread_mutex_unlock(&philo->read);
	if (time_since_meal >= philo->data->time_to_die)
		return (1);
	return (0);
}

int	someone_died(t_philo *philos)
{
	size_t	i;
	t_data	*data;

	if (!philos)
		return (1);
	data = philos[0].data;
	i = -1;
	while (++i < data->philos_nb)
	{
		if (is_dead(&philos[i]))
		{
			pthread_mutex_lock(&data->dead_mtx);
			if (!data->end)
			{
				data->end = true;
				pthread_mutex_unlock(&data->dead_mtx);
				pthread_mutex_lock(&data->print);
				printf(CR"%ld %d died"CE, get_time() \
				- data->start, philos[i].id);
			}
			pthread_mutex_unlock(&data->print);
			return (1);
		}
	}
	return (0);
}

int	everyone_ate(t_philo *philos)
{
	size_t		i;
	size_t		full_count;
	t_data		*data;

	data = philos[0].data;
	full_count = 0;
	i = -1;
	if ((int)data->max_meals == -1)
		return (0);
	while (++i < data->philos_nb)
	{
		pthread_mutex_lock(&philos[i].full_lock);
		if (philos[i].full)
			full_count++;
		pthread_mutex_unlock(&philos[i].full_lock);
	}
	if (full_count >= data->philos_nb)
	{
		pthread_mutex_lock(&data->dead_mtx);
		data->end = true;
		pthread_mutex_unlock(&data->dead_mtx);
		return (1);
	}
	return (0);
}

void	*monitoring(void *ptr)
{
	t_data	*data;
	t_philo	*philos;

	data = (t_data *)ptr;
	philos = data->philos;
	if (!philos)
		return (NULL);
	while (!simulation_ended(philos))
	{
		if ((someone_died(philos) == true || everyone_ate(philos) == true))
			break ;
		if (philos->data->philos_nb >= 100)
			usleep(1);
		else
			usleep(data->time_to_die / 10);
	}
	return (ptr);
}
