/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:37:58 by ihadj             #+#    #+#             */
/*   Updated: 2025/06/06 16:18:47 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;

	size = 0;
	if ((char)c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	size = ft_strlen(s);
	while (size--)
	{
		if ((char)c == s[size])
			return ((char *)(s + size));
	}
	return (NULL);
}
