/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:24:35 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/23 17:45:32 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// ==========================[ Libs & Macros ]==========================

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define INTMAX     2147483647
# define PHILO_MAX  200
# define MIN_TIME   60

// ==========[ Colors ANSI ]==========

# define E  "\033[0m"
# define CI "\n"
# define CE "\033[0m\n"
# define CR "\033[0;41m"
# define CV "\033[0;32m"
# define CM "\033[0;33m"
# define CY "\033[38;5;220m"
# define CA "\033[0;36m"
# define CG "\033[2;39m"
# define G  "\033[1m"
# define IT "\033[3m"

// ===========================[ Structs ]=============================

typedef struct s_philo	t_philo;

typedef struct s_data
{
	size_t			philos_nb;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			max_meals;

	size_t			start;
	bool			end;
	bool			all_full;
	int				all_set;

	pthread_mutex_t	start_mtx;
	pthread_mutex_t	dead_mtx;
	pthread_mutex_t	print;
	pthread_mutex_t	all_full_mtx;
	pthread_mutex_t	threads_set;

	t_philo			*philos;
}	t_data;

typedef struct s_philo
{
	int				id;
	long			meals;
	bool			full;
	long			last_meal;

	pthread_t		thread;
	t_philo			*right_philo;
	t_data			*data;

	pthread_mutex_t	fork;
	pthread_mutex_t	read;
	pthread_mutex_t	full_lock;
}	t_philo;

// ==========================[ Parse and init ]============================

int			parse(int ac, char **av);
int			init_data(t_data *data, char **av);
t_philo		*init_philos(t_data *data);
int			input_error(char *msg, void (*hint)(void));
void		wrong_format(void);
void		wrong_range(void);

// ===========================[ Loop ]=====================================

int			start_simulation(t_philo *philos);
int			init_threads(t_philo *philos);
void		*monitoring(void *ptr);
void		*routine(void *arg);
void		wait_threads(t_philo *philos, size_t threads_nb);

// ==========================[ Routine actions ]===========================

void		eat(t_philo *philo);
void		nap(t_philo *philo);
void		think(t_philo *philo);
void		eat_alone(t_philo *philo);
void		print_action(t_philo *philo, char *msg);

// ===========================[ Monitoring ]===============================

int			someone_died(t_philo *philos);
int			everyone_ate(t_philo *philos);
int			is_dead(t_philo *philo);
bool		simulation_ended(t_philo *philo);

// ===========================[ Time gestion ]==============================

long		get_time(void);
int			ft_usleep(size_t milliseconds, t_philo *philo);

// ===========================[ Utils ]=====================================

int			ft_isdigit(int c);
size_t		ft_atoi_secure(const char *str, size_t *data);
void		ft_putstr_fd(char *s, int fd);
void		clean_exit(t_philo *philos, int i);
int			error_exit(t_philo *philos, int i);
char		*generate_color(int id);

#endif
