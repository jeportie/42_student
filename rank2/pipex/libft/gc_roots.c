/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_roots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:50:19 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/05 15:29:21 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	gc_add_root(void **root_ptr)
{
	t_gc_root	*new_root;

	new_root = (t_gc_root *)malloc(sizeof(t_gc_root));
	if (!new_root)
		return ;
	new_root->root_ptr = root_ptr;
	new_root->next = g_garbage_collector.roots;
	g_garbage_collector.roots = new_root;
	ft_printf("Added root pointer: %p\n", root_ptr);
}

void	gc_remove_root(void **root_ptr)
{
	t_gc_root	*current;
	t_gc_root	*prev;

	current = g_garbage_collector.roots;
	prev = NULL;
	while (current)
	{
		if (current->root_ptr == root_ptr)
		{
			if (prev)
				prev->next = current->next;
			else
				g_garbage_collector.roots = current->next;
			free(current);
			ft_printf("Removed root pointer: %p\n", root_ptr);
			return ;
		}
	prev = current;
	current = current->next;
	}
}

void gc_add_local_root(void **root_ptr)
{
    t_gc_root *new_root;

    new_root = (t_gc_root *)malloc(sizeof(t_gc_root));
    if (!new_root)
        return;
    new_root->root_ptr = root_ptr;
    new_root->next = g_garbage_collector.local_roots;
    g_garbage_collector.local_roots = new_root;
    ft_printf("Added local root pointer: %p\n", root_ptr); // Debugging print
}

void gc_remove_local_root(void **root_ptr)
{
    t_gc_root *current = g_garbage_collector.local_roots;
    t_gc_root *prev = NULL;

    while (current)
    {
        if (current->root_ptr == root_ptr)
        {
            if (prev)
                prev->next = current->next;
            else
                g_garbage_collector.local_roots = current->next;
            free(current);
            ft_printf("Removed local root pointer: %p\n", root_ptr); // Debugging print
            return;
        }
        prev = current;
        current = current->next;
    }
}
