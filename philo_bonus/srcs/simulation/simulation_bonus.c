/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:07:30 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/25 14:00:52 by ihadj            ###   ########.fr       */
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
	if (philo->data->philos_nb > 1 && philo->id % 2 != 0)
		ft_usleep(philo->data->time_to_eat * 0.9, philo);
	while (!simulation_ended(philo))
	{
		eat(philo);
		nap(philo);
		think(philo);
	}
	// pause() qui serait une fonction ou je sleep time to die
	return (NULL);
}

int	create_processes(t_philo *philos)
{
	int		i;
	pid_t	pid;

	i = -1;
	while (++i < philos->data->philos_nb)
	{
		pid = fork();
		if (pid == -1)
			return (0);
		if (pid == 0)
		{
			sem_wait(philos[i].data->start);
			philos[i].start_time = get_time();
			philos[i].last_meal = philos->start_time;
			create_thread(&philos[i]);
			routine(&philos[i]);
			if (philos[i].full)
				exit(FULL_CODE);
			if (philos[i].dead)
				exit(DEAD_CODE);
		}
		else
			philos->data->pids[i] = pid;
	}
	i = -1;
	while (++i < philos->data->philos_nb)
		sem_post(philos[i].data->start);
	return (1);
}
