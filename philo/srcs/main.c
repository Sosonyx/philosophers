/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:37:34 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/23 14:57:38 by ihadj            ###   ########.fr       */
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
	start_simulation(philos);
	clean_exit(philos, philos->data->philos_nb);
	return (0);
}
