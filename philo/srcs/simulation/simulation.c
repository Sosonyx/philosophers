/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:07:30 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/22 19:23:11 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	start_simulation(t_philo *philos)
{
	pthread_t	monitor;
	size_t		i;
	size_t		start_time;

	if (!init_threads(philos))
		return (1);
	pthread_mutex_lock(&philos->data->start_mtx);
	start_time = get_time();
	philos->data->start = start_time;
	i = -1;
	while (++i < philos->data->philos_nb)
		philos[i].last_meal = start_time;
	pthread_mutex_unlock(&philos->data->start_mtx);
	if (pthread_create(&monitor, NULL, &monitoring, philos->data) != 0)
		return (ft_putstr_fd("Monitor creation failed\n", 2), 0);
	wait_threads(philos, philos->data->philos_nb);
	pthread_join(monitor, NULL);
	return (1);
}
