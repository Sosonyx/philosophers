/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:33:54 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/26 17:43:01 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	clean_exit(t_philo *philos, int exit_code)
{
	if (philos && philos->data->start)
		sem_close(philos->data->start);
	if (philos && philos->data->death)
		sem_close(philos->data->death);
	if (philos && philos->data->print)
		sem_close(philos->data->print);
	if (philos && philos->data->forks)
		sem_close(philos->data->forks);
	if (philos && philos->data->write)
		sem_close(philos->data->write);
	if (philos && philos->data->pids)
		free(philos->data->pids);
	if (philos)
		free(philos);
	exit(exit_code);
}

void	one_death_exit(t_philo *philo, pid_t pid)
{
	int		i;

	i = 0;
	while (i < philo->data->philos_nb)
	{
		if (philo->data->pids[i] != pid)
			kill(philo->data->pids[i], SIGKILL);
		i++;
	}
	sem_close(philo->data->start);
	sem_close(philo->data->death);
	sem_close(philo->data->print);
	sem_close(philo->data->forks);
	sem_close(philo->data->write);
	free(philo->data->pids);
	free(philo);
	exit(0);
}

int	wait_pids(t_philo *philos)
{
	int		i;
	int		status;
	int		exit_code;
	pid_t	pid;
	int		all_eat;

	all_eat = 0;
	status = 0;
	i = -1;
	while (++i < philos->data->philos_nb && all_eat != philos->data->philos_nb)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == -1)
			break ;
		if (WIFEXITED(status))
		{
			exit_code = WEXITSTATUS(status);
			if (exit_code == DEAD_CODE)
				return (one_death_exit(philos, philos->data->pids[i]), 0);
			if (exit_code == FULL_CODE)
				all_eat++;
		}
	}
	return (0);
}
