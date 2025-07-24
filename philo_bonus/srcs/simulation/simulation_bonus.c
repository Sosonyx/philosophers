/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:07:30 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/24 19:24:26 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

// clean thread >>>

bool	simulation_ended(t_philo *philo)
{
	if (philo->full == true || philo->dead == true)
		return (true);
	return (false);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	sem_wait(philo->data->start);
	philo->start_time = get_time();
	while (!simulation_ended(philo))
	{
		eat(philo);
		nap(philo);
		think(philo);
	}
	return (NULL);
}

int	create_processes(t_philo *philos)
{
	size_t	i;
	pid_t	pid;
	i = -1;
	while (++i < philos->data->philos_nb)
	{
		pid = fork();
		if (pid == -1)
			return (0);
		if (pid == 0)
		{
			create_thread(&philos[i]);
			routine(&philos[i]);
		}
		else
			philos->data->pids[i] = pid;
	}
	i = -1;
	while (++i < philos->data->philos_nb)
		sem_post(philos[i].data->start);
	return (1);
}
