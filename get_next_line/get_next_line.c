/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:43:00 by jeportie          #+#    #+#             */
/*   Updated: 2024/01/23 17:18:32 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*mem_src;

	mem_src = (unsigned char *)s;
	while (n--)
		*mem_src++ = (unsigned char)c;
	return (s);
}

char	*ft_read_buffer(int fd, char *buffer)
{
	char	read_buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	if (fd <= 0)
		return (NULL);
	while (!ft_strchr(buffer, '\n'))
	{
		ft_memset(read_buffer, 0, BUFFER_SIZE + 1);
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (!bytes_read && buffer && *buffer)
				return (buffer);
			return (NULL);
		}
		if (!buffer)
			buffer = ft_strdup(read_buffer);
		else	
			buffer = ft_strjoin(buffer, read_buffer);
		if (!buffer)
			return (NULL);
	}
	return (buffer);
}

char	*ft_extract_line(char *buffer)
{
	size_t	i;
	size_t	len;
	char	*line;

	i = 0;
	len = 0;
	if (buffer == NULL || buffer[0] == '\0')
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		len = i + 1;
	else if (buffer[i] == '\0')
		len = i;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	line[len] = '\0';
	return (line);
}

char	*ft_update_buffer(char *buffer)
{
	char	*new_buffer;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = malloc(sizeof(char) * (ft_strlen(buffer) - i));
	if (!new_buffer)
		return (NULL);
	i++;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_extract_line(buffer);
	buffer = ft_update_buffer(buffer);
	return (line);
}
