/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_collect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:23:26 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/13 16:04:26 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void gc_collect()
{
	gc_mark_from_roots();
	gc_sweep();
}

void	gc_mark_from_roots(void)
{
	if (g_game)
		gc_mark(g_game);
	if (g_map)
		gc_mark(g_map);
}

void	gc_mark(void *ptr)
{
	t_gc_node	*current;
	void		**array;

	current = g_garbage_collector.head;
	while (current)
	{
		if (current->ptr == ptr)
		{
			if (current->marked)
				return ;
			current->marked = 1;
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
		if (!current->marked)
		{
			if (prev)
				prev->next = current->next;
			else
				g_garbage_collector.head = current->next;
			if (current->fd)
				close(current->fd);
			if (current->mlx_option == DESTROY_IMAGE)
				mlx_destroy_image(current->ptr, current->img);
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
			current->marked = 0;
			prev = current;
			current = current->next;
		}
	}
}
