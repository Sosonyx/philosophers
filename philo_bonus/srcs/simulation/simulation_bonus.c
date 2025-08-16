/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:07:30 by ihadj             #+#    #+#             */
/*   Updated: 2025/08/16 17:06:21 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

bool	simulation_ended(t_philo *philo)
{
	sem_wait(philo->data->write);
	if (philo->full == true || philo->dead == true)
		return (sem_post(philo->data->write), true);
	sem_post(philo->data->write);
	return (false);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->philos_nb == 1)
	{
		print_action(philo, "has taken a fork");
		ft_usleep(philo->data->time_to_die, philo);
		return (NULL);
	}
	if (philo->data->philos_nb > 1 && philo->id % 2 != 0)
		ft_usleep(philo->data->time_to_eat * 0.9, philo);
	while (!simulation_ended(philo))
	{
		eat(philo);
		if (simulation_ended(philo))
			return (NULL);
		nap(philo);
		if (simulation_ended(philo))
			return (NULL);
		think(philo);
		if (philo->data->philos_nb == 3 || philo->data->philos_nb == 5)
			ft_usleep((philo->data->time_to_eat), philo);
	}
	return (NULL);
}

int	is_full(t_philo philo)
{
	sem_wait(philo.data->read);
	if (philo.full)
	{
		sem_post(philo.data->read);
		return (1);
	}
	sem_post(philo.data->read);
	return (0);
}

int	create_processes(t_philo *philos)
{
	int			i;
	pid_t		pid;
	pthread_t	thread;

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
			philos[i].last_meal = philos[i].start_time;
			thread = create_thread(&philos[i]);
			routine(&philos[i]);
			pthread_join(thread, NULL);
			sem_wait(philos[i].data->write);
			if (philos[i].dead)
			{
				sem_post(philos[i].data->write);
				child_exit(&philos[i], DEAD_CODE, i);
			}
			sem_post(philos[i].data->write);
			child_exit(&philos[i], FULL_CODE, i);
		}
		else
			philos->data->pids[i] = pid;
	}
	i = -1;
	while (++i < philos->data->philos_nb)
		sem_post(philos[i].data->start);
	return (1);
}
