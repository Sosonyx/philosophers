/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printinghexa.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:53:50 by ihadj             #+#    #+#             */
/*   Updated: 2025/06/12 13:50:22 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printadress(void *adr)
{
	int	count;

	count = 0;
	if (!adr)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	count += ft_putstr("0x");
	count += ft_putnbr_adress(adr);
	return (count);
}

int	ft_putnbr_base(unsigned int adr, char *base)
{
	int		count;

	count = 0;
	if (adr > 15)
		count += ft_putnbr_base(adr / 16, base);
	count++;
	ft_putchar(base[adr % 16]);
	return (count);
}

int	ft_putnbr_adress(void *adr)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if ((unsigned long long)adr > 15)
		count += ft_putnbr_adress((void *)((unsigned long long)adr / 16));
	count++;
	ft_putchar(base[(unsigned long long)adr % 16]);
	return (count);
}
