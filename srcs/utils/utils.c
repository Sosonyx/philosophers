/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:50:55 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/20 19:52:01 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ft_atoi_secure(const char *str, size_t *data)
{
	long	result;
	int		i;

	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		return (0);
	if (str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result > INTMAX)
			return (0);
		i++;
	}
	if (str[i] != '\0')
		return (0);
	*data = (size_t)result;
	return (1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	print_action(t_philo *philo, char *msg)
{
	long	timestamp;
	char	*color;

	pthread_mutex_lock(&philo->data->dead_mtx);
	if (philo->data->end)
	{
		pthread_mutex_unlock(&philo->data->dead_mtx);
		return ;
	}
	color = generate_color(philo->id);
	pthread_mutex_unlock(&philo->data->dead_mtx);
	timestamp = get_time() - philo->data->start;
	pthread_mutex_lock(&philo->data->print);
	printf("%s%ld %d %s%s\n",color, timestamp, philo->id, msg, E);
	pthread_mutex_unlock(&philo->data->print);
}
