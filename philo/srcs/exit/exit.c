/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:33:54 by ihadj             #+#    #+#             */
/*   Updated: 2025/08/15 14:25:58 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait_threads(t_philo *philos, size_t threads_nb)
{
	size_t	i;

	i = 0;
	while (i < threads_nb)
		pthread_join(philos[i++].thread, NULL);
}

void	clean_exit(t_philo *philos, int mtx_already_init)
{
	int	j;

	j = -1;
	if (!philos)
		return ;
	while (++j < mtx_already_init)
	{
		pthread_mutex_destroy(&philos[j].read);
		pthread_mutex_destroy(&philos[j].fork);
		pthread_mutex_destroy(&philos[j].full_lock);
	}
	pthread_mutex_destroy(&philos->data->all_full_mtx);
	pthread_mutex_destroy(&philos->data->start_mtx);
	pthread_mutex_destroy(&philos->data->dead_mtx);
	pthread_mutex_destroy(&philos->data->print);
	pthread_mutex_destroy(&philos->data->threads_set);
	if (philos->data->all_set == -42)
	{
		free(philos);
		return ;
	}
	free(philos);
}

int	error_exit(t_philo *philos, int i)
{
	ft_putstr_fd("Thread creation failed\n", 2);
	wait_threads(philos, i);
	clean_exit(philos, i);
	return (1);
}
