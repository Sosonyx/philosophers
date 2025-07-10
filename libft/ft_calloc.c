/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:05:35 by ihadj             #+#    #+#             */
/*   Updated: 2025/04/28 14:32:10 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb && (size > SIZE_MAX / nmemb))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

// #include <stdio.h>
// int main(void)
// {
// 	int *tab = ft_calloc(432423, sizeof(int));
// 	for (int i = 0; i < 100; i++)
// 		printf("%d",tab[i]);
//  free(tab);
// }