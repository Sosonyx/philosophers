/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting_gestion_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:14:14 by ihadj             #+#    #+#             */
/*   Updated: 2025/08/16 17:14:33 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers_bonus.h>

static int	wait_death(t_philo *philos, int *dead_pid)
{
	int		status;
	pid_t	pid;

	while (1)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == -1)
			break ;
		if (WIFEXITED(status) && WEXITSTATUS(status) == DEAD_CODE)
		{
			*dead_pid = pid;
			one_death_exit(philos, pid);
			return (1);
		}
	}
	return (0);
}

static int	wait_full(t_philo *philos)
{
	int		i;
	int		status;
	int		all_eat;
	pid_t	pid;

	all_eat = 0;
	i = 0;
	while (i < philos->data->philos_nb)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == -1)
			break ;
		if (WIFEXITED(status) && WEXITSTATUS(status) == FULL_CODE)
			all_eat++;
		i++;
	}
	return (all_eat == philos->data->philos_nb);
}

int	wait_pids(t_philo *philos)
{
	int	dead_pid;

	dead_pid = -1;
	if (wait_death(philos, &dead_pid))
		return (0);
	wait_full(philos);
	return (0);
}
