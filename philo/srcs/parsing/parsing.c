/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:38:00 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/20 21:30:44 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_valid_number(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i] || !(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_if_args_are_numbers(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_valid_number(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (wrong_format(), 0);
	if (!check_if_args_are_numbers(ac, av))
		return (wrong_range(), 0);
	return (1);
}
