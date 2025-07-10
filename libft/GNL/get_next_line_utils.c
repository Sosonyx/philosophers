/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:36:49 by ihadj             #+#    #+#             */
/*   Updated: 2025/06/06 16:15:12 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*join_bf_and_tmp(char *s1, char *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	joined = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2[j])
		joined[i++] = s2[j++];
	joined[i] = '\0';
	return (joined);
}

char	*extract_line(char *str)
{
	int		len;
	char	*line;
	int		i;

	len = 0;
	if (!str)
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = str[i];
		i++;
	}
	line[len] = '\0';
	return (line);
}

char	*extract_rest(char *str)
{
	int		i;
	int		j;
	char	*rest;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (NULL);
	i++;
	if (!str[i])
		return (NULL);
	rest = malloc(sizeof(char) * (ft_strlen(str + i) + 1));
	if (!rest)
		return (NULL);
	while (str[i])
		rest[j++] = str[i++];
	rest[j] = '\0';
	return (rest);
}
