/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_launch_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:27:37 by ihadj             #+#    #+#             */
/*   Updated: 2025/08/16 17:28:03 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers_bonus.h>

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
