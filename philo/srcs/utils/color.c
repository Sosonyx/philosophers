/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:20:47 by ihadj             #+#    #+#             */
/*   Updated: 2025/07/21 16:01:48 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static char	*build_color(char *buf, int color)
{
	int	i;

	buf[0] = '\033';
	buf[1] = '[';
	buf[2] = '3';
	buf[3] = '8';
	buf[4] = ';';
	buf[5] = '5';
	buf[6] = ';';
	i = 7;
	if (color >= 100)
	{
		buf[i++] = '0' + (color / 100);
		buf[i++] = '0' + ((color / 10) % 10);
		buf[i++] = '0' + (color % 10);
	}
	else
	{
		if (color >= 10)
			buf[i++] = '0' + (color / 10);
		buf[i++] = '0' + (color % 10);
	}
	buf[i++] = 'm';
	buf[i] = '\0';
	return (buf);
}

char	*generate_color(int id)
{
	static char	colors[201][20];
	int			color;

	if (!colors[id][0])
	{
		color = 16 + (id * 37) % 215;
		build_color(colors[id], color);
	}
	return (colors[id]);
}
