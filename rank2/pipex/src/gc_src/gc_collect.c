/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_collect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:23:26 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/25 17:27:36 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void gc_collect(void)
{
	gc_mark_from_roots();
	gc_sweep();
}

//void	gc_mark_from_roots(void)
//{
//	if (g_game)
//		gc_mark(g_game);
//	if (g_map)
//		gc_mark(g_map);
//}

void	gc_mark(void *ptr)
{
	t_gc_node	*current;
	void		**array;

	current = g_garbage_collector.head;
	while (current)
	{
		if (current->ptr == ptr)
		{
			if (current->is_marked)
				return ;
			current->is_marked = true;
			if (current->is_array)
			{
				array = (void **)current->ptr;
				while (*array)
				{
					gc_mark(*array);
					array++;
				}
			}
			return ;
		}
		current = current->next;
	}
}

void	gc_sweep(void)
{
	t_gc_node	*current;
	t_gc_node	*prev;

	current = g_garbage_collector.head;
	prev = NULL;
	while (current)
	{
		if (!current->is_marked)
		{
			if (prev)
				prev->next = current->next;
			else
				g_garbage_collector.head = current->next;
			if (current->fd)
				close(current->fd);
			else
				free(current->ptr);
			free(current);
			if (prev)
				current = prev->next;
			else
				current = g_garbage_collector.head;
		}
		else
		{
			current->is_marked = 0;
			prev = current;
			current = current->next;
		}
	}
}
