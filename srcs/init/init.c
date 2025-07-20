/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:06:12 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/20 21:26:46 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_data(t_data *data, char **av)
{
	if (!ft_atoi_secure(av[1], &data->philos_nb)
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
		if (!ft_atoi_secure(av[5], &data->max_meals)
			|| data->max_meals <= 0)
			return (input_error("Invalid max_meals", wrong_range));
	}
	data->start = 0;
	data->end = false;
	data->all_full = false;
	return (1);
}


void	init_philo_mtx(t_philo *philo)
{
	pthread_mutex_init(&philo->read, NULL);
	pthread_mutex_init(&philo->fork, NULL);
	pthread_mutex_init(&philo->full_lock, NULL);
}

void	init_shared_mtx(t_data *data)
{
	pthread_mutex_init(&data->all_full_mtx, NULL);
	pthread_mutex_init(&data->start_mtx, NULL);
	pthread_mutex_init(&data->dead_mtx, NULL);
	pthread_mutex_init(&data->print, NULL);
}

t_philo	*init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	init_shared_mtx(data);
	philos = malloc(sizeof(t_philo) * data->philos_nb);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < (int)data->philos_nb)
	{
		philos[i].id = i + 1;
		philos[i].meals = 0;
		philos[i].eating = false;
		philos[i].full = false;
		philos[i].last_meal = 0;
		philos[i].thread = 0;
		philos[i].data = data;
		philos[i].right_philo = &philos[(i + 1) % data->philos_nb];
		init_philo_mtx(&philos[i]);
		i++;
	}
	data->philos = philos;
	return (philos);
}
