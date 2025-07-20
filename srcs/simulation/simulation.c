/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:07:30 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/20 21:35:03 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	one_philo_case(t_philo *philo)
{
	if (philo->data->philos_nb == 1)
	{
		printf("0 1 has taken a fork\n");
		ft_usleep(philo->data->time_to_die, philo);
		printf("%zu 1 died\n", philo->data->time_to_die);
		return (1);
	}
	return (0);
}

int	start_simulation(t_philo *philos)
{
	pthread_t	monitor;
	size_t		i;
	size_t		start_time;

	if (one_philo_case(philos))
		return (0);
	if (init_threads(philos))
		return (1);
	pthread_mutex_lock(&philos->data->start_mtx);
	start_time = get_time();
	philos->data->start = start_time;
	for (i = 0; i < philos->data->philos_nb; i++)
		philos[i].last_meal = start_time;
	pthread_mutex_unlock(&philos->data->start_mtx);
	if (pthread_create(&monitor, NULL, &monitoring, philos->data) != 0)
		return (ft_putstr_fd("Monitor creation failed\n", 2), 1);
	wait_threads(philos);
	pthread_join(monitor, NULL);
	return (0);
}

