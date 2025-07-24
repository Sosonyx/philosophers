/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:08:49 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/23 13:35:24 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	take_his_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	print_action(philo, "has taken a fork");
}

void	eat_alone(t_philo *philo)
{
	take_his_fork(philo);
	pthread_mutex_unlock(&philo->fork);
	ft_usleep(philo->data->time_to_eat, philo);
}
