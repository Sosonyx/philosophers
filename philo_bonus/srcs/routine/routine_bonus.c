/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:38:56 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/29 14:07:34 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	release_forks(t_philo *philo)
{
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

/*
	Take the right fork then their fork/
	OR their fork then right one
*/
static void	take_forks(t_philo *philo)
{
	if (simulation_ended(philo))
		return ;
	sem_wait(philo->data->forks);
	if (simulation_ended(philo))
	{
		sem_post(philo->data->forks);
		return ;
	}
	print_action(philo, "has taken a fork");
	sem_wait(philo->data->forks);
	if (simulation_ended(philo))
	{
		release_forks(philo);
		return ;
	}
	print_action(philo, "has taken a fork");
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	if (simulation_ended(philo))
		return ;
	sem_wait(philo->data->write);
	philo->last_meal = get_time();
	sem_post(philo->data->write);
	print_action(philo, "is eating");
	ft_usleep(philo->data->time_to_eat, philo);
	release_forks(philo);
	philo->meals++;
	if (philo->data->max_meals > 0 && \
		philo->meals >= (long)philo->data->max_meals)
	{
		sem_wait(philo->data->write);
		philo->full = true;
		sem_post(philo->data->write);
	}
}

void	nap(t_philo *philo)
{
	if (simulation_ended(philo))
		return ;
	print_action(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep, philo);
}

/* 
	think and let a quick window to others threads
	to do their cycle
*/
void	think(t_philo *philo)
{
	if (simulation_ended(philo))
		return ;
	print_action(philo, "is thinking");
}
