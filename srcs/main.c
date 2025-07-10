/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:37:34 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/10 17:08:18 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
    t_philo *philos;
    t_data  *data;

    (void)ac;
    philos = NULL;
    data = NULL;
    if (!init(philos, data, av))
        ft_putstr_fd("Init error\n", 2);
    
}