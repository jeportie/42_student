/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:12:43 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/03 11:31:19 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H

# include "libft.h"
# include <errno.h>
# include <stdbool.h>
# include <stdarg.h>

typedef struct s_gc_node1
{
	void				*ptr;
	bool				is_marked;
	bool				is_array;
	int					fd;
	struct s_gc_node	*next;
}				t_gc_node1;

typedef struct s_garbage_collector1
{
	t_gc_node	*head;
}				t_gc1;

extern t_gc		g_garbage_collector;

/* Garbage_collector function */
void	*gc_malloc(size_t size);
void	gc_register(void *ptr);
void	gc_nest_register(void *ptr);
void	gc_fd_register(int fd);
void	gc_cleanup(void);
void	gc_collect(const char *format, ...);

#endif /*GARBAGE_H*/
