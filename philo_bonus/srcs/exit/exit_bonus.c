/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:33:54 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/24 19:13:07 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	one_death_exit(t_philo *philo, pid_t pid)
{
	size_t	i;

	i = 0;
	while (i < philo->data->philos_nb)
	{
		if (philo->data->pids[i] != pid)
			kill(philo->data->pids[i], SIGTERM);
		i++;
	}
	sem_close(philo->data->start);
	sem_close(philo->data->death);
	sem_close(philo->data->print);
	sem_close(philo->data->forks);
	free(philo->data->pids);
	free(philo);	
}

int	wait_pids(t_philo *philos)
{
	size_t	i;
	int		status;
	int		exit_code;
	pid_t	pid;

	status = 0;
	i = -1;
	while (++i < philos->data->philos_nb)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == -1)
			break ;
		if (WIFEXITED(status))
		{
			exit_code = WEXITSTATUS(status);
			if (exit_code == DEAD_CODE)
				return (one_death_exit(philos, philos->data->pids[i]), 42);
			if (exit_code == FULL_CODE)
				i++;
		}
	}
	return (0);
}

