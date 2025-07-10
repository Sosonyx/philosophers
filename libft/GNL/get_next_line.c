/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:28:39 by ihadj             #+#    #+#             */
/*   Updated: 2025/06/23 19:11:48 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	check_if_n(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*read_buffer_and_create_tmp(int fd, char **tmp, char **tmp2)
{
	int		count;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(*tmp), *tmp = NULL);
	count = 1;
	while (!check_if_n(*tmp) && (count > 0))
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count > 0)
		{
			buffer[count] = '\0';
			*tmp2 = join_bf_and_tmp(*tmp, buffer);
			if (!*tmp2)
				return (free(buffer), free(*tmp), *tmp = NULL, NULL);
			*tmp = (free(*tmp), *tmp2);
		}
	}	
	if (count < 0)
		return (free(buffer), free(*tmp), *tmp = NULL, NULL);
	if ((!*tmp || !**tmp))
		return (free(buffer), free(*tmp), *tmp = NULL, NULL);
	return (free(buffer), *tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp = NULL;
	char		*tmp2;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = read_buffer_and_create_tmp(fd, &tmp, &tmp2);
	line = extract_line(tmp);
	if (!line)
		tmp = (free(tmp), NULL);
	tmp2 = extract_rest(tmp);
	free(tmp);
	tmp = tmp2;
	return (line);
}
