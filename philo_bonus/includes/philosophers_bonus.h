/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:15:28 by ihadj             #+#    #+#             */
/*   Updated: 2025/08/16 17:05:22 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

// ==========================[ Libs & Macros ]==========================

# include <semaphore.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <signal.h>

# define INTMAX     2147483647
# define PHILO_MAX  200
# define MIN_TIME   60

# define DEAD_CODE 2
# define FULL_CODE 3

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
	int				philos_nb;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				max_meals;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*death;
	sem_t			*start;
	sem_t			*write;
	sem_t			*read;
	sem_t			*print_lock;
	pid_t			*pids;
}	t_data;

typedef struct s_philo
{
	int				id;
	long			meals;
	bool			full;
	bool			dead;
	long			last_meal;
	size_t			start_time;
	t_data			*data;

}	t_philo;

// ==========================[ Parse and init ]============================

int			parse(int ac, char **av);
int			init_data(t_data *data, char **av);
t_philo		*init_philos(t_data *data);
int			input_error(char *msg, void (*hint)(void));
void		wrong_format(void);
void		wrong_range(void);

// ===========================[ Utils ]=====================================

int			ft_isdigit(int c);
size_t		ft_atoi_secure(const char *str, size_t *data);
void		ft_putstr_fd(char *s, int fd);
void		clean_exit(t_philo *philos, int exit_code);
void		child_exit(t_philo *philos, int exit_code, int i);

char		*generate_color(int id);
void		one_death_exit(t_philo *philo, pid_t pid);

// ===========================[ Loop ]=====================================

void		*monitoring(void *ptr);
void		*routine(void *arg);
int			create_processes(t_philo *philos);

// ==========================[ Routine actions ]===========================

void		eat(t_philo *philo);
void		nap(t_philo *philo);
void		think(t_philo *philo);
void		print_action(t_philo *philo, char *msg);

// ===========================[ Monitoring ]===============================

bool		simulation_ended(t_philo *philo);
pthread_t	create_thread(t_philo *philo);

// ===========================[ Time gestion ]==============================

long		get_time(void);
int			ft_usleep(size_t milliseconds, t_philo *philo);
int			wait_pids(t_philo *philos);

#endif