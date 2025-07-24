/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:39:30 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/23 12:52:58 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time(void)
{
	struct timeval	tv;
	long			ms;

	gettimeofday(&tv, NULL);
	ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (ms);
}

int	ft_usleep(size_t milliseconds, t_philo *philo)
{
	size_t	start;
	size_t	now;
	size_t	diff;

	start = get_time();
	now = start;
	while (now - start < milliseconds)
	{
		if (simulation_ended(philo))
			break ;
		diff = milliseconds - (now - start);
		if (diff > 5)
			usleep(500);
		else
			usleep(100);
		now = get_time();
	}
	return (0);
}
