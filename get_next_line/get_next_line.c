/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:43:00 by jeportie          #+#    #+#             */
/*   Updated: 2024/01/29 18:40:34 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

void *ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void *new_ptr;

    if (new_size <= old_size)
        return ptr;

    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
        return (NULL);
    if (ptr != NULL)
    {
        ft_memcpy(new_ptr, ptr, old_size);
        free(ptr);
    }
    return new_ptr;
}

size_t next_capacity(size_t required_capacity)
{
    size_t capacity = 1;
    while (capacity < required_capacity)
        capacity *= 2;
    return capacity;
}

char *ft_append_to_buffer(char *buffer, char *read_buffer, ssize_t bytes_read)
{
    size_t  current_size;
    size_t  capacity;
    char    *new_buffer;

    current_size = (buffer) ? ft_strlen(buffer) : 0;
    capacity = current_size + 1;

    if (current_size + bytes_read + 1 > capacity)
    {
        capacity = next_capacity(current_size + bytes_read + 1);
        new_buffer = (char *)ft_realloc(buffer, current_size, capacity);
        if (new_buffer == NULL)
            return (NULL);  // Memory allocation failure
        buffer = new_buffer;
    }
    if (buffer)
        ft_memcpy(buffer + current_size, read_buffer, bytes_read + 1);
    return (buffer);
}

char *ft_read_buffer(int fd, char *buffer)
{
    char    *read_buffer;
    ssize_t bytes_read;

    if (fd < 0)
        return (NULL);

    read_buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (read_buffer == NULL)
        return (NULL);

    while ((bytes_read = read(fd, read_buffer, BUFFER_SIZE)) > 0)
    {
        read_buffer[bytes_read] = '\0';
        buffer = ft_append_to_buffer(buffer, read_buffer, bytes_read);
        if (buffer == NULL || ft_strchr(read_buffer, '\n'))
            break;
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
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_update_buffer(buffer);
	return (line);
}
