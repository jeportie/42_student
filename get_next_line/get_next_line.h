/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:14:49 by jeportie          #+#    #+#             */
/*   Updated: 2024/02/01 14:45:26 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_read_buffer(int fd, char *buffer);
char	*ft_extract_line(char *buffer);
char	*ft_update_buffer(char *buffer);
char	*ft_strjoin_gnl(char const *s1, char const *s2);

/* utils functions */
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
#endif /* GET_NEXT_LINE_H */

