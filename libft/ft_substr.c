/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:51:53 by ihadj             #+#    #+#             */
/*   Updated: 2025/06/06 16:18:51 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	slen;
	size_t	i;

	i = 0;
	slen = ft_strlen(s);
	if (start >= slen)
	{
		ptr = malloc(sizeof(char) * 1);
		if (!ptr)
			return (NULL);
		return (ptr[0] = '\0', ptr);
	}
	if (len > slen - start)
		len = slen - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (s[i + start] && (i < len))
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
