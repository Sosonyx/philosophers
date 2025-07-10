/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:06:12 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/10 17:07:47 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_data(t_data *data, char **av)
{
	data->philos_nb = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	data->max_meals = ft_atol(av[5]);
	data->start = 0;
	data->end = 0;
	data->forks = NULL;
}

int	init_philo(t_philo *philos)
{
	long	i;

	if (!philos || !philos->data)
		return (0);
	i = -1;
	while (++i < philos->data->philos_nb)
	{
		philos[i].id = i + 1;
		philos[i].meals = 0;
		philos[i].full = 0;
		philos[i].last_meal = philos->data->start;
		philos[i].data = philos->data;
	}
	return (1);
}

int	init(t_philo *philos, t_data *data, char **av)
{
	long	i;

	i = 0;
	if (!philos || !data)
		return (1);
	init_data(data, av);
	while (i++ < data->philos_nb)
		philos[i].data = data;
	if (!init_philo(philos))
		return (1);
	return (0);
}