/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_collect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:23:26 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/05 15:35:25 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdarg.h>

static void	gc_mark(void *ptr);
static void	gc_sweep(void);

void	gc_collect(void)
{
	t_gc_root	*root;
	t_gc_root	*local_root;

	local_root = g_garbage_collector.local_roots;
	root = g_garbage_collector.roots;
	while (root)
	{
		if (*root->root_ptr)
		{
			ft_printf("Collecting and marking root pointer: %p\n",
				*root->root_ptr);
			gc_mark(*root->root_ptr);
		}
	root = root->next;
	}
	while (local_root)
	{
		if (*local_root->root_ptr)
		{
			ft_printf("Collecting and marking local root pointer: %p\n",
				*local_root->root_ptr);
			gc_mark(*local_root->root_ptr);
		}
		local_root = local_root->next;
	}
	gc_sweep();
}

static void	gc_delete_node(t_gc_node **prev, t_gc_node **current)
{
	t_gc_node	*next_node;

	next_node = (*current)->next;
	if (*prev)
		(*prev)->next = next_node;
	else
		g_garbage_collector.head = next_node;
	if ((*current)->fd > -1)
		close((*current)->fd);
	else
		free((*current)->ptr);
	free(*current);
	*current = next_node;
}

static void	gc_mark(void *ptr)
{
	t_gc_node	*current;
	void		**array;

	ft_printf("Marking pointer: %p\n", ptr);
	current = g_garbage_collector.head;
	while (current)
	{
		if (current->ptr == ptr)
		{
			ft_printf("Found node: %p\n", current->ptr);
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

static void	gc_sweep(void)
{
	t_gc_node	*current;
	t_gc_node	*prev;

	current = g_garbage_collector.head;
	prev = NULL;
	while (current)
	{
		if (!current->is_marked)
		{
			ft_printf("Deleting node: %p\n", current->ptr);
			gc_delete_node(&prev, &current);
		}
		else
		{
			current->is_marked = false;
			prev = current;
			current = current->next;
		}
	}
}
