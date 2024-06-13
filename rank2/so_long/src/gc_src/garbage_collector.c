/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:13:24 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/13 16:48:27 by jeportie         ###   ########.fr       */
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
	new_node->img = NULL;
	new_node->fd = 0;
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
	new_node->img = NULL;
	new_node->fd = 0;
	new_node->next = g_garbage_collector.head;
	g_garbage_collector.head = new_node;
}

void	gc_fd_register(int fd)
{
	t_gc_node	*new_node;

	if (!fd)
		return ;
	new_node = malloc(sizeof(t_gc_node));
	if (!new_node)
	{
		errno = ENOMEM;
		return ;
	}
	new_node->ptr = NULL;
	new_node->marked = 0;
	new_node->is_array = 0;
	new_node->mlx_option = 0;
	new_node->img = NULL;
	new_node->fd = fd;
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
	new_node->img = NULL;
	new_node->fd = 0;
	new_node->next = g_garbage_collector.head;
	g_garbage_collector.head = new_node;
}

void	gc_mlx_image_register(t_img *img, void *mlx_ptr)
{
	t_gc_node	*new_node;

	if (!img || !mlx_ptr)
		return ;
	new_node = malloc(sizeof(t_gc_node));
	if (!new_node)
	{
		errno = ENOMEM;
		return ;
	}
	new_node->ptr = mlx_ptr;
	new_node->marked = 0;
	new_node->is_array = 0;
	new_node->mlx_option = DESTROY_IMAGE;
	new_node->img = img;
	new_node->fd = 0;
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
		if (current->fd)
			close(current->fd);
		next = current->next;
		if (current->mlx_option == DESTROY_IMAGE)
			mlx_destroy_image(current->ptr, current->img);
		else
		{
			free(current->ptr);
			current->ptr = NULL;
		}
		free(current);
		current = next;
	}
	g_garbage_collector.head = NULL;
}
