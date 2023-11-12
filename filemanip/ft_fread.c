/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:19:05 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/12 18:31:51 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filemanip.h"

char	*ft_fread(int fd, size_t len)
{
	char	*buffer;
	ssize_t	bytes_read;

	if (fd < 0 || len == 0)
		return (NULL);
	buffer = (char *)malloc(len * sizeof(unsigned char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, len);
	if (bytes_read < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (bytes_read < len)
		buffer[bytes_read] = '\0';
	return (buffer);
}
