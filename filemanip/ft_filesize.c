/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filesize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:28:06 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/12 20:44:28 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filemanip.h"

size_t	ft_filesize(const char *filepath)
{
	int		fd;
	size_t	file_size;

	fd = ft_fopen(filepath, O_RDONLY); 
	file_size = lseek(fd, 0, SEEK_END);
	ft_fclose(fd);
	if (file_size == -1)
		return (-1);
	return (file_size);
}
