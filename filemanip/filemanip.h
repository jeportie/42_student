/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filemanip.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:03:38 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/13 23:22:49 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEMANIP_H
# define FILEMANIP_H

# define FLINE_BUFFER_SIZE 512

#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

//FUNCTION THAT OPEN AND CLOSES THE FILE INSIDE THE FUNCTION
size_t	ft_filesize(const char *filepath);
int		ft_count_flines(const char *filepath);
char	**ft_flines_to_str(const char *filepath);
//FUNCTION THAT WORKS WITH THE FILE DESCRIPTOR OF AN OPEN FILE
int		ft_fopen(const char *filepath, int option);
char	*ft_fread(int fd, size_t len);
void	ft_fclose(int fd);

#endif /*FILEMANIP_H*/
