/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:02:25 by ihadj             #+#    #+#             */
/*   Updated: 2025/06/06 16:18:02 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	charc;
	unsigned char	*s1;

	charc = (unsigned char)c;
	s1 = (unsigned char *)s;
	while (n--)
	{
		if (charc == *s1)
			return ((unsigned char *)(s1));
		s1++;
	}
	return (NULL);
}
