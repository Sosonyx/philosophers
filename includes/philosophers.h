/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:38:25 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/20 21:26:40 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# define INTMAX 2147483647
# define PHILO_MAX 200
# define MIN_TIME 60

# define CI "\n"         // '\n'
# define E "\033[0m"     // COLOR END
# define CE "\033[0m\n"  // COLOR END + '\n'
# define CR "\033[0;41m" // COLOR RED
# define CV "\033[0;32m" // COLOR GREEN
# define CM "\033[0;33m" // COLOR BROWN
# define CY "\033[38;5;220m" // COLOR YELLOW
# define CA "\033[0;36m" // COLOR AZUR
# define CG "\033[2;39m" // COLOR GREY
# define G "\033[1m"
# define IT	"\033[3m"

typedef struct s_philo	t_philo;

typedef struct s_data
{
	size_t					philos_nb;
	size_t					time_to_die;
	size_t					time_to_eat;
	size_t					time_to_sleep;
	size_t					max_meals;
	size_t					start;
	bool					end;
	bool					all_full;
	pthread_mutex_t			start_mtx;
	pthread_mutex_t			dead_mtx;
	pthread_mutex_t			print;
	pthread_mutex_t			all_full_mtx;
	t_philo					*philos;
}	t_data;

typedef struct s_philo
{
	int					id;
	long				meals;
	bool				eating;
	bool				full;
	long				last_meal;
	pthread_t			thread;
	t_philo				*right_philo;
	t_data				*data;
	pthread_mutex_t		fork;
	pthread_mutex_t		read;
	pthread_mutex_t		full_lock;
}	t_philo;

void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);

int		parse(int ac, char **av);

int		init_data(t_data *data, char **av);
t_philo	*init_philos(t_data *data);

size_t	ft_atoi_secure(const char *str, size_t *data);

// time 
long	get_time(void);
int		ft_usleep(size_t milliseconds, t_philo *philos);

void	*routine(void	*arg);
int		init_threads(t_philo *philos);
int		everyone_ate(t_philo *philos);
int		someone_died(t_philo *philos);
int		is_dead(t_philo *philo);
void	*monitoring(void *ptr);
int		start_simulation(t_philo *philos);
void	clean_exit(t_philo *philos);
void	print_action(t_philo *philo, char *msg);
void	eat(t_philo *philo);
void	think(t_philo *philo);
void	nap(t_philo *philo);
void	think(t_philo *philo);
void	wait_threads(t_philo *philos);
bool	simulation_ended(t_philo *philo);
void	smart_delay(t_philo *philo);
int		input_error(char *msg, void (*hint)(void));
void	wrong_range(void);
void	wrong_format(void);
char	*generate_color(int id);

#endif