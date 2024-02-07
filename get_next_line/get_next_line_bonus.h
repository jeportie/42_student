/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:16:14 by jeportie          #+#    #+#             */
/*   Updated: 2024/02/07 12:44:59 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct s_fd_list
{
	int					fd;
	char				*buffer;
	struct s_fd_list	*next;
}						t_fd_list;

char		*get_next_line_bonus(int fd);
char		*ft_read_buffer_bonus(int fd, char *buffer, t_fd_list **top);

/* utils functions */
t_fd_list	*ft_find_fd(t_fd_list **top, int fd);
t_fd_list	*ft_list_new(int fd);
t_fd_list	*ft_lstlast(t_fd_list *lst);
void		ft_lstadd_back(t_fd_list **lst, t_fd_list *new);
void		ft_lstdelone(t_fd_list **lst, int fd);

#endif /* GET_NEXT_LINE_H */
