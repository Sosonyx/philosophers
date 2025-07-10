/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihadj <ihadj@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:47:51 by ihadj             #+#    #+#             */
/*   Updated: 2025/06/06 16:17:07 by ihadj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*first;

	first = malloc(sizeof(t_list) * 1);
	if (!first)
		return (NULL);
	first->content = content;
	first->next = NULL;
	return (first);
}
