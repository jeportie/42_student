/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfmanip.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:03:38 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/28 12:44:47 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEMANIP_H
# define FILEMANIP_H

# define FLINE_BUFFER_SIZE 512

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

//EXTRA LIBFT
void 			ft_strtoupper(char *str);
//MAIN FUNCTIONS
char		    **ft_flines_to_str(const char *filepath);
int			    ft_count_flines(const char *filepath);
size_t		    ft_filesize(const char *filepath);
//FILE AND LIST UTILITARIES
int			    ft_fopen(const char *filepath, int option);
char		    *ft_fread(int fd, size_t len);
int			    ft_fclose(int fd);
#endif /*FILEMANIP_H*/
