/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:48:42 by ihadj             #+#    #+#             */
/*   Updated: 2025/06/06 16:18:06 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;

	src2 = (unsigned char *)src;
	dest2 = (unsigned char *)dest;
	if (!dest2 && !src2)
		return (NULL);
	if (dest2 > src2)
	{
		ft_memmove(dest, src, n);
		return (dest);
	}
	while (n--)
	{
		*dest2 = *src2;
		dest2++;
		src2++;
	}
	return (dest);
}
