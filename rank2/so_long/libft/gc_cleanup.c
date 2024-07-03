/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:09:32 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/03 11:38:40 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	gc_cleanup(void)
{
	t_gc_node	*current;
	t_gc_node	*next;

	current = g_garbage_collector.head;
	while (current)
	{
		if (current->fd)
			close(current->fd);
		next = current->next;
		if (current->ptr)
		{
			free(current->ptr);
			current->ptr = NULL;
		}
		free(current);
		current = next;
	}
	g_garbage_collector.head = NULL;
}
