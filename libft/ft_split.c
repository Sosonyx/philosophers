/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:43:43 by ihadj             #+#    #+#             */
/*   Updated: 2025/06/06 16:18:22 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		while (str[i] && str[i] == c)
			i++;
	}
	return (count);
}

static char	*malloc_word(const char *str, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_tab(char **tab, int index)
{
	while (--index >= 0)
		free(tab[index]);
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[j++] = malloc_word(&s[i], c);
			if (!tab[j - 1])
				return (free_tab(tab, j), NULL);
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (tab[j] = NULL, tab);
}
