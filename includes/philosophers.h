/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:38:25 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/10 17:07:53 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "libft.h"
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}	t_fork;

typedef struct s_data
{
	long	philos_nb;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	max_meals;
	long	start;
	int		end;
	t_fork	*forks;
}	t_data;

typedef struct s_philo
{
	int			id;
	long		meals;
	int			full;
	long		last_meal;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread;
	t_data		*data;
	int			ac;
	char		**av;
	
}	t_philo;


void	init_data(t_data *data, char **av);
int 	init_philo(t_philo *philos);
int		init(t_philo *philos, t_data *data, char **av);

long	ft_atol(const char *str);

#endif