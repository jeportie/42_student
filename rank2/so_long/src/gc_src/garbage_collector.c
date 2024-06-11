/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:13:24 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/11 20:35:28 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_gc	g_garbage_collector = {NULL};
t_game	*g_game = NULL;
t_map	*g_map = NULL;

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
	new_node->marked = 0;
	new_node->is_array = 0;
	new_node->mlx_option = 0;
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
	new_node->marked = 0;
	new_node->is_array = 0;
	new_node->mlx_option = 0;
	new_node->next = g_garbage_collector.head;
	g_garbage_collector.head = new_node;
}

void	gc_nest_register(void *ptr)
{
	t_gc_node	*new_node;
	void		**array;

	if (!ptr)
		return ;
	array = (void **)ptr;
	while (*array)
	{
		gc_register(*array);
		array++;
	}
	new_node = malloc(sizeof(t_gc_node));
	if (!new_node)
	{
		errno = ENOMEM;
		return ;
	}
	new_node->ptr = ptr;
	new_node->marked = 0;
	new_node->is_array = 1;
	new_node->mlx_option = 0;
	new_node->next = g_garbage_collector.head;
	g_garbage_collector.head = new_node;
}

void	gc_mlx_register(void *ptr, int mlx_destroy_code, t_game *data)
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
	new_node->marked = 0;
	new_node->is_array = 0;
	new_node->game = data;
	new_node->mlx_option = mlx_destroy_code;
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
		current->ptr = NULL;
		free(current);
		current = next;
	}
	g_garbage_collector.head = NULL;
}
