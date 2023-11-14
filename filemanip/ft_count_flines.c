/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_flines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:43:12 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/14 00:12:30 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filemanip.h"

int	ft_count_flines(const char *filepath)
{
	int		fd;
	int		count;
	size_t	filesize;
	size_t	i;
	char	*buffer;

	fd = ft_fopen(filepath, O_RDONLY);
	count = 0;
	filesize = ft_filesize(filepath);
	buffer = ft_fread(fd, filesize);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			count++;
	}
	count++;
	ft_fclose(fd);
	return (count);
}
