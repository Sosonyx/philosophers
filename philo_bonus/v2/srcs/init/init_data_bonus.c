/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:06:12 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/26 17:22:40 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	init_sems(t_data *data)
{
	sem_unlink("/fork");
	sem_unlink("/print");
	sem_unlink("/dead");
	sem_unlink("/start");
	sem_unlink("/write");
	data->forks = sem_open("/fork", O_CREAT | O_EXCL, 0644, data->philos_nb);
	data->print = sem_open("/print", O_CREAT | O_EXCL, 0644, 1);
	data->death = sem_open("/dead", O_CREAT | O_EXCL, 0644, 1);
	data->start = sem_open("/start", O_CREAT | O_EXCL, 0644, 0);
	data->write = sem_open("/write", O_CREAT | O_EXCL, 0644, 1);
}

int	init_data(t_data *data, char **av)
{
	if (!ft_atoi_secure(av[1], (size_t *)&data->philos_nb)
		|| data->philos_nb <= 0 || data->philos_nb > PHILO_MAX)
		return (input_error("Invalid number of philosophers", wrong_range));
	if (!ft_atoi_secure(av[2], &data->time_to_die)
		|| data->time_to_die < MIN_TIME)
		return (input_error("Invalid time_to_die", wrong_range));
	if (!ft_atoi_secure(av[3], &data->time_to_eat)
		|| data->time_to_eat < MIN_TIME)
		return (input_error("Invalid time_to_eat", wrong_range));
	if (!ft_atoi_secure(av[4], &data->time_to_sleep)
		|| data->time_to_sleep < MIN_TIME)
		return (input_error("Invalid time_to_sleep", wrong_range));
	if (av[5])
	{
		if (!ft_atoi_secure(av[5], (size_t *)&data->max_meals)
			|| data->max_meals <= 0)
			return (input_error("Invalid max_meals", wrong_range));
	}
	else
		data->max_meals = -1;
	init_sems(data);
	return (1);
}
