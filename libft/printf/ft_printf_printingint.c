/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printingint.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:19:27 by ihadj             #+#    #+#             */
/*   Updated: 2025/06/12 13:50:38 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		count += ft_putstr("-2147483648");
		return (11);
	}
	if (nb < 0)
	{
		nb = -nb;
		count += ft_putchar('-');
	}
	if (nb > 9)
		count += ft_putnbr(nb / 10);
	count++;
	ft_putchar((nb % 10) + '0');
	return (count);
}

int	ft_unsignedputnbr(unsigned int nb)
{
	int		count;
	char	c;

	count = 0;
	if (nb > 9)
		count = ft_unsignedputnbr(nb / 10);
	count++;
	c = ((nb % 10) + '0');
	write(1, &c, 1);
	return (count);
}
