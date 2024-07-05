/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:09:32 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/05 14:15:03 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	gc_cleanup(void)
{
	t_gc_node	*current;
	t_gc_node	*next;
	t_gc_root	*root_current;
	t_gc_root	*root_next;

	current = g_garbage_collector.head;
	while (current)
	{
		next = current->next;
		if (current->fd > -1)
			close(current->fd);
		else
			free(current->ptr);
		free(current);
		current = next;
	}
	g_garbage_collector.head = NULL;
	root_current = g_garbage_collector.roots;
	while (root_current)
	{
		root_next = root_current->next;
		free(root_current);
		root_current = root_next;
	}
	g_garbage_collector.roots = NULL;
}
