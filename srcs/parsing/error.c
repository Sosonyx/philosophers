/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:52:27 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/20 19:56:43 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	input_error(char *msg, void (*error_fct)(void))
{
	ft_putstr_fd(CA, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(CE, 2);
	if (error_fct)
		error_fct();
	return (0);
}

void	wrong_range(void)
{
	printf("\n");
	ft_putstr_fd(CV"				 "CR">>>"G" Bad input range <<<"E, 2);
	printf("\n\n");
	printf(CY"	*	<nb_of_philo> : "
		"Value must be between 1 and 200				*"CE);
	printf(CY"	*	<time_to_die> : "
		"Minimum value: 60, maximum: INT_MAX			*"CE);
	printf(CY"	*	<time_to_eat> : "
		"Minimum value: 60, maximum: INT_MAX			*"CE);
	printf(CY"	*	<time_to_sleep> : "
		"Minimum value: 60, maximum: INT_MAX			*"CE);
	printf(CY"	*	<max_meals_per_philo> : "
		"Minimum value: 60, maximum: INT_MAX			*"CE);
	printf(CE);
}

void	wrong_format(void)
{
	printf("\n");
	ft_putstr_fd(CV"				 "CR">>>"G" Wrong format <<<"E, 2);
	printf("\n\n");
	printf(CY"	*	<nb_of_philo> : "
		"The number of philosophers				*"CE);
	printf(CY"	*	<time_to_die> : The time it takes for a"
		" philosopher to die.		*"CE);
	printf(CY"	*	<time_to_eat> : The time it takes for a"
		" philosopher to eat.		*"CE);
	printf(CY"	*	<time_to_sleep> : The time a"
		" philosopher will spend sleeping.		*"CE);
	printf(CY"	*	<max_meals_per_philo> :"
		" Max meal per philosophers.			*"CE);
	printf(CE);
}
