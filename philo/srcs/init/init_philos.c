/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:22:14 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/23 15:53:04 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_philo_mtx(t_philo *philo)
{
	pthread_mutex_init(&philo->read, NULL);
	pthread_mutex_init(&philo->fork, NULL);
	pthread_mutex_init(&philo->full_lock, NULL);
}

static void	init_shared_mtx(t_data *data)
{
	pthread_mutex_init(&data->all_full_mtx, NULL);
	pthread_mutex_init(&data->start_mtx, NULL);
	pthread_mutex_init(&data->dead_mtx, NULL);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->threads_set, NULL);
}

t_philo	*init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	init_shared_mtx(data);
	philos = malloc(sizeof(t_philo) * data->philos_nb);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < (int)data->philos_nb)
	{
		philos[i].id = i + 1;
		philos[i].meals = 0;
		philos[i].full = false;
		philos[i].last_meal = 0;
		philos[i].thread = 0;
		philos[i].data = data;
		philos[i].right_philo = &philos[(i + 1) % data->philos_nb];
		init_philo_mtx(&philos[i]);
		i++;
	}
	data->philos = philos;
	return (philos);
}
