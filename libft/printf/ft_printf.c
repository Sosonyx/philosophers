/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:57:34 by ihadj             #+#    #+#             */
/*   Updated: 2025/06/06 16:03:49 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		count;

	count = 0;
	va_start(list, str);
	count += check_ifpourcent(str, list);
	va_end(list);
	return (count);
}
