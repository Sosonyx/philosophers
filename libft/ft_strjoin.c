/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:21:58 by ihadj             #+#    #+#             */
/*   Updated: 2025/06/16 18:50:51 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1size;
	size_t	s2size;
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	s1size = ft_strlen(s1);
	s2size = ft_strlen(s2);
	if (s2)
		ptr = ft_calloc(s1size + s2size + 1, sizeof(char));
	if (!s2 || !ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while ((i + j) < (s1size + s2size + 1))
	{
		ptr[i + j] = s2[j];
		j++;
	}
	return (ptr);
}
