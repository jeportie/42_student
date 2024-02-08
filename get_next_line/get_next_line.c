/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:28:11 by jeportie          #+#    #+#             */
/*   Updated: 2024/02/08 23:15:02 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

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

char	*ft_read_buffer_to_static(int fd, char *static_buffer)
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
		static_buffer = ft_strjoin_gnl(static_buffer, read_buffer);
		if (!static_buffer || ft_strchr(read_buffer, '\n'))
			break ;
		bytes_read = read(fd, read_buffer, size);
	}
	free(read_buffer);
	return (static_buffer);
}

char	*ft_extract_line(char *static_buffer)
{
	size_t	i;
	size_t	len;
	char	*line;

	i = 0;
	len = 0;
	if (static_buffer == NULL || static_buffer[0] == '\0')
		return (NULL);
	while (static_buffer[i] != '\0' && static_buffer[i] != '\n')
		i++;
	if (static_buffer[i] == '\n')
		len = i + 1;
	else if (static_buffer[i] == '\0')
		len = i;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = static_buffer[i];
		i++;
	}
	line[len] = '\0';
	return (line);
}

char	*ft_update_static_buffer(char *static_buffer)
{
	char	*new_buffer;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	if (!static_buffer[i])
	{
		free(static_buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc(sizeof(char) *(ft_strlen(static_buffer) - i));
	if (!new_buffer)
		return (NULL);
	i++;
	while (static_buffer[i])
		new_buffer[j++] = static_buffer[i++];
	new_buffer[j] = '\0';
	free(static_buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_buffer = ft_read_buffer_to_static(fd, static_buffer);
	if (!static_buffer)
		return (NULL);
	line = ft_extract_line(static_buffer);
	if (!line)
	{
		free(static_buffer);
		static_buffer = NULL;
		return (NULL);
	}
	static_buffer = ft_update_static_buffer(static_buffer);
	return (line);
}
