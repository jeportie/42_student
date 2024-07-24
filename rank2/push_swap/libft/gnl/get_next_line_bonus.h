/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:32:49 by neleon            #+#    #+#             */
/*   Updated: 2024/05/28 18:33:11 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

// get_next_line
char	*get_next_line(int fd, int flag);
char	*gnl_read_and_store(int fd, char *buf);
char	*gnl_extract_line(char **chars_rd);
char	*gnl_intit_buf(void);

// get_next_line_utils
int		gnl_strlen(char *s);
char	*gnl_substr(char *s, unsigned int start, size_t len);
char	*gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strdup(char *s1);

#endif
