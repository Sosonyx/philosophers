/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:37:34 by ihadj             #+#    #+#             */
/*   Updated: 2025/08/15 15:05:31 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_philo		*philos;
	t_data		data;

	if (!parse(ac, av))
		return (1);
	if (!init_data(&data, av))
		return (1);
	philos = init_philos(&data);
	if (!philos)
		return (ft_putstr_fd("Bad init\n", 2), 1);
	if (!start_simulation(philos))
		return (ft_putstr_fd("Failing to start the simulation\n", 2), 1);
	clean_exit(philos, philos->data->philos_nb);
	return (0);
}
