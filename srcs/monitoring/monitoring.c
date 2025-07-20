/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:41:18 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/20 21:34:02 by ihadj            ###   ########.fr       */
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
			return (ft_putstr_fd("Thread creation failed\n", 2), 1);
	}
	return (0);
}

int	someone_died(t_philo *philos)
{
	size_t	i;
	t_data	*data;

	if (!philos)
		return (1);
	data = philos[0].data;
	i = 0;
	while (i < data->philos_nb)
	{
		if (is_dead(&philos[i]))
		{
			pthread_mutex_lock(&data->dead_mtx);
			if (!data->end)
			{
				data->end = true;
				pthread_mutex_lock(&data->print);
				printf(CR"%ld %d died\n", get_time() - data->start, philos[i].id);
				pthread_mutex_unlock(&data->print);
			}
			pthread_mutex_unlock(&data->dead_mtx);
			return (1);
		}
		i++;
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
	while (++i < data->philos_nb)
	{
		pthread_mutex_lock(&philos[i].full_lock);
		if (philos[i].full)
			full_count++;
		pthread_mutex_unlock(&philos[i].full_lock);
	}
	if (full_count == data->philos_nb)
	{
		pthread_mutex_lock(&data->dead_mtx);
		data->end = true;
		pthread_mutex_unlock(&data->dead_mtx);
		return (1);
	}
	return (0);
}

int	is_dead(t_philo *philo)
{
	size_t	time_since_meal;

	pthread_mutex_lock(&philo->read);
	time_since_meal = get_time() - philo->last_meal;
	pthread_mutex_unlock(&philo->read);
	if (time_since_meal > philo->data->time_to_die)
		return (1);
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
		if ((someone_died(philos) == 1 || everyone_ate(philos) == 1))
			break ;
		ft_usleep(100, philos);
	}
	return (ptr);
}
