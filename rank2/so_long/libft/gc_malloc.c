/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:20:13 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/03 11:39:27 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*gc_malloc(size_t size)
{
	t_gc_node	*new_node;
	void		*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		errno = ENOMEM;
		return (NULL);
	}
	new_node = malloc(sizeof(t_gc_node));
	if (!new_node)
	{
		free(ptr);
		errno = ENOMEM;
		return (NULL);
	}
	new_node->ptr = ptr;
	new_node->is_marked = false;
	new_node->is_array = false;
	new_node->fd = 0;
	new_node->next = g_garbage_collector.head;
	g_garbage_collector.head = new_node;
	return (ptr);
}
