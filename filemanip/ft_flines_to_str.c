/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flines_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:25:34 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/14 00:05:20 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filemanip.h"

char	**ft_flines_to_str(const char *filepath)
{
	char	**data_array;
	int		fd;
	size_t	filesize;
	char	*buffer;

	fd = ft_fopen(filepath, O_RDONLY);
	filesize = ft_filesize(filepath);
	buffer = (char *)malloc((sizeof(unsigned char) * filesize));
	if (!buffer)
		return (NULL);
	buffer = ft_fread(fd, filesize); 
	data_array = ft_split(buffer, '\n');
	free(buffer);
	ft_fclose(fd);
	return (data_array);
}
