/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_flines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:43:12 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/28 03:48:02 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

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
	if (!buffer)
	{
		ft_fclose(fd);
		return (-1);
	}
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n' || buffer[i+1] == '\0')
			count++;
		i++;
	}
	ft_fclose(fd);
	free(buffer);
	return (count);
}
