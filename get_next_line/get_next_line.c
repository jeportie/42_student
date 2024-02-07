/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:28:11 by jeportie          #+#    #+#             */
/*   Updated: 2024/02/07 12:58:10 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	len1;
	size_t	len2;
	size_t	total_len;

	len1 = 0;
	if (!s2)
		return (NULL);
	if (s1)
		len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	total_len = len1 + len2;
	joined_str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!joined_str)
		return (NULL);
	if (s1)
		ft_memcpy(joined_str, s1, len1);
	ft_memcpy(joined_str + len1, s2, len2);
	joined_str[total_len] = '\0';
	if (s1)
		free((void *)s1);
	return (joined_str);
}

char	*ft_read_buffer(int fd, char *buffer)
{
	char	*read_buffer;
	ssize_t	bytes_read;
	int		size;

	size = BUFFER_SIZE;
	if (size < 4)
		size = 4;
	if (fd < 0)
		return (NULL);
	read_buffer = (char *)malloc(size + 1);
	if (!read_buffer)
		return (NULL);
	bytes_read = read(fd, read_buffer, size);
	while (bytes_read > 0)
	{
		read_buffer[bytes_read] = '\0';
		buffer = ft_strjoin_gnl(buffer, read_buffer);
		if (!buffer || ft_strchr(read_buffer, '\n'))
			break ;
		bytes_read = read(fd, read_buffer, size);
	}
	free(read_buffer);
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
	new_buffer = (char *)malloc(sizeof(char) *(ft_strlen(buffer) - i));
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
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_update_buffer(buffer);
	return (line);
}
