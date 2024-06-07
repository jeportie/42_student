/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:13:24 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/07 13:09:11 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_gc	g_garbage_collector = {NULL};

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
	new_node->next = g_garbage_collector.head;
	g_garbage_collector.head = new_node;
	return (ptr);
}

void	gc_register(void *ptr)
{
	t_gc_node	*new_node;

	if (!ptr)
		return ;
	new_node = malloc(sizeof(t_gc_node));
	if (!new_node)
	{
		errno = ENOMEM;
		return ;
	}
	new_node->ptr = ptr;
	new_node->next = g_garbage_collector.head;
	g_garbage_collector.head = new_node;
}

void	gc_cleanup(void)
{
	t_gc_node	*current;
	t_gc_node	*next;

	current = g_garbage_collector.head;
	while (current)
	{
		next = current->next;
		free(current->ptr);
		free(current);
		current = next;
	}
	g_garbage_collector.head = NULL;
}
