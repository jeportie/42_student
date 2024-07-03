/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_collect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:23:26 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 10:59:10 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdarg.h>

static void	gc_mark(void *ptr);
static void	gc_sweep(void);

void	gc_collect(const char *format, ...)
{
	va_list	args;
	int		i;
	void	*ptr;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == 'p')
		{
			ptr = va_arg(args, void *);
			gc_mark(ptr);
		}
		i++;
	}
	va_end(args);
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
	if ((*current)->fd)
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
			gc_delete_node(&prev, &current);
		}
		else
		{
			current->is_marked = 0;
			prev = current;
			current = current->next;
		}
	}
}
