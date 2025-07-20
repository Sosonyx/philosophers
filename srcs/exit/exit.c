/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:33:54 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/20 15:51:36 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait_threads(t_philo *philos)
{
	size_t	i;

	i = 0;
	while (i < philos->data->philos_nb)
		pthread_join(philos[i++].thread, NULL);
}

void	clean_exit(t_philo *philos)
{
	int	i;

	i = -1;
	if (!philos)
		return ;
	while (++i < (int)philos->data->philos_nb)
	{
		pthread_mutex_destroy(&philos[i].data->all_full_mtx);
		pthread_mutex_destroy(&philos[i].data->start_mtx);
		pthread_mutex_destroy(&philos[i].data->dead_mtx);
		pthread_mutex_destroy(&philos[i].data->print);
		pthread_mutex_destroy(&philos[i].read);
		pthread_mutex_destroy(&philos[i].fork);
		pthread_mutex_destroy(&philos[i].full_lock);
	}
	free(philos);
}
