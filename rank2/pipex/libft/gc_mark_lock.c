/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_roots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:50:19 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/05 21:57:27 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	gc_mark(void *ptr)
{
	t_gc_node	*current;

	current = g_garbage_collector.head;
	while (current)
	{
		if (current->ptr == ptr)
		{
			if (current->is_marked)
				return ;
			current->is_marked = true;
			return ;
		}
		current = current->next;
	}
}

void	gc_lock(void *ptr)
{
	t_gc_node	*current;

	current = g_garbage_collector.head;
	while (current)
	{
		if (current->ptr == ptr)
		{
			current->is_locked = true;
			return ;
		}
		current = current->next;
	}
}

void	gc_unlock(void *ptr)
{
	t_gc_node	*current;

	current = g_garbage_collector.head;
	while (current)
	{
		if (current->ptr == ptr)
		{
			current->is_locked = false;
			return ;
		}
		current = current->next;
	}
}
