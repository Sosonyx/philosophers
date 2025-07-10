/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_checking.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:43:20 by ihadj             #+#    #+#             */
/*   Updated: 2025/06/12 13:50:07 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	check_type(const char *str, va_list arg, int i)
{
	int	count;

	count = 0;
	if (str[i] == 'd' || str[i] == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (str[i] == 'u')
		count += ft_unsignedputnbr(va_arg(arg, unsigned int));
	else if (str[i] == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (str[i] == 'x')
		count += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (str[i] == 'X')
		count += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (str[i] == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (str[i] == '%')
		count += ft_putchar('%');
	else if (str[i] == 'p')
		count += ft_printadress(va_arg(arg, void *));
	return (count);
}

int	check_ifpourcent(const char *str, va_list arg)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += check_type(str, arg, i);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}
