/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:16:14 by jeportie          #+#    #+#             */
/*   Updated: 2024/02/08 23:02:44 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_fd_list
{
	int					fd;
	char				*buffer;
	struct s_fd_list	*next;
}						t_fd_list;

char		*get_next_line(int fd);
char		*ft_read_buffer(int fd, char *buffer);
char		*ft_extract_line(char *buffer);
char		*ft_update_buffer(char *buffer);
char		*ft_strjoin_gnl(char const *s1, char const *s2);

/* utils functions */
t_fd_list	*ft_find_fd(t_fd_list **top, int fd);
t_fd_list	*ft_list_new(int fd);
t_fd_list	*ft_lstlast(t_fd_list *lst);
void		ft_lstadd_back(t_fd_list **lst, t_fd_list *new);
void		ft_lstdelone(t_fd_list **lst, int fd);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);
#endif /* GET_NEXT_LINE_H */
