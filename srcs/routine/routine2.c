/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:14:44 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/20 21:35:22 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
	Take the right fork then their fork/
	OR their fork then right one
*/
static void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->right_philo->fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(&philo->fork);
		print_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(&philo->right_philo->fork);
		print_action(philo, "has taken a fork");
	}
}

static void	release_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->right_philo->fork);
	}
	else
	{
		pthread_mutex_unlock(&philo->right_philo->fork);
		pthread_mutex_unlock(&philo->fork);
	}
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->read);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->read);
	print_action(philo, "is eating");
	ft_usleep(philo->data->time_to_eat, philo);
	philo->meals++;
	if (philo->meals >= (long)philo->data->max_meals)
	{
		pthread_mutex_lock(&philo->full_lock);
		philo->full = true;
		pthread_mutex_unlock(&philo->full_lock);
	}
	release_forks(philo);
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
	ft_usleep(5, philo);
}
