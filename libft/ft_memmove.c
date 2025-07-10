/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:33:50 by ihadj             #+#    #+#             */
/*   Updated: 2025/06/06 16:18:09 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src2;
	unsigned char	*dest2;

	src2 = (unsigned char *)src;
	dest2 = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	if (dest2 < src2)
		while (n--)
			*dest2++ = *src2++;
	else
		while (n--)
			dest2[n] = src2[n];
	return (dest);
}
