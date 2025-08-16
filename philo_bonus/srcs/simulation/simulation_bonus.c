/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:07:30 by ihadj             #+#    #+#             */
/*   Updated: 2025/08/16 17:42:51 by ihadj            ###   ########.fr       */
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

/*
	The child wait infront of the GLOBAL sem START
	Then they launch their monitoring
	Launch the routine
	Check if DEAD or FULL then return the correct CODE
*/
static void	child_routine(t_philo *philos, int i)
{
	pthread_t	thread;

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

static int	fork_one(t_philo *philos, int i)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
		child_routine(philos, i);
	philos->data->pids[i] = pid;
	return (1);
}

/*
	Create as many sub-process as there is philos
	When they are all forked, we post the GLOBAL start
	(nb of philos) times to make them start their routine
*/
int	create_processes(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->data->philos_nb)
		if (!fork_one(philos, i))
			return (0);
	i = -1;
	while (++i < philos->data->philos_nb)
		sem_post(philos[i].data->start);
	return (1);
}
