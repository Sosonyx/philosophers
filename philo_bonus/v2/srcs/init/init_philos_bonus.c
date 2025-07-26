/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:22:14 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/25 15:43:54 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

t_philo	*init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * data->philos_nb);
	if (!philos)
		return (NULL);
	data->pids = malloc(sizeof(pid_t) * data->philos_nb);
	if (!data->pids)
		return (NULL);
	i = 0;
	while (i < data->philos_nb)
	{
		philos[i].id = i + 1;
		philos[i].meals = 0;
		philos[i].full = false;
		philos[i].dead = false;
		philos[i].last_meal = 0;
		philos[i].data = data;
		philos[i].start_time = 0;
		i++;
	}
	return (philos);
}
