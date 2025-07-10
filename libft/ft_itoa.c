/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:54:05 by ihadj             #+#    #+#             */
/*   Updated: 2025/06/06 16:17:47 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int nb)
{
	int		size;

	size = 0;
	if (nb <= 0)
		size += 1;
	while (nb != 0)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;
	long	nb;

	nb = n;
	size = ft_intlen(n);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	while (nb)
	{
		str[--size] = (nb % 10 + '0');
		nb /= 10;
	}
	return (str);
}
