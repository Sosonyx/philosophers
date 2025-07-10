/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:32:20 by ihadj             #+#    #+#             */
/*   Updated: 2025/06/06 16:18:29 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	fft_toupper(unsigned int index, char *str)
// {
// 	if ((index % 2 == 0) && (*str >= 'a' && *str <= 'z'))
// 		*str -= 32;
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s && !f)
		return ;
	while (*s)
		f(i++, s++);
}
