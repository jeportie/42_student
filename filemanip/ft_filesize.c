/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filesize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:28:06 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/28 03:48:23 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

size_t	ft_filesize(const char *filepath)
{
	int		fd;
	off_t	file_size;

	fd = ft_fopen(filepath, O_RDONLY); 
	if (fd == -1)
		return ((size_t)-1);
	file_size = lseek(fd, 0, SEEK_END);
	ft_fclose(fd);
	if (file_size == -1)
		return ((size_t)-1);
	return ((size_t)file_size);
}
