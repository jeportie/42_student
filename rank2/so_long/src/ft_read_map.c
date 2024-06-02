/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 00:51:27 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/03 01:36:57 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_read_map(char *filename, t_map *data);

int		ft_count_lines(char *filename);
void	ft_allocate_map(t_map *data);
void	ft_store_map(char *filename, t_map *data);

void	ft_read_map(char *filename, t_map *data)
{
	ft_memset(data, -1, sizeof(t_map));
	data->height = ft_count_lines(filename);
	ft_allocate_map(data);
	ft_store_map(filename, data);
}

int	ft_count_lines(char *filename)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error!\nFailed to open map file.");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void	ft_allocate_map(t_map *data)
{
	data->map = (char **)malloc(sizeof (char *) * (data->height + 1));
	if (!data->map)
	{
		perror("Error!\nMemory allocation failed");
		exit(EXIT_FAILURE);
	}
}

void	ft_store_map(char *filename, t_map *data)
{
	int		fd;
	char	*line;
	int	i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error!\nFailed to open map file");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		data->map[i++] = line;
		line = get_next_line(fd);
	}
	data->map[i] = NULL;
	close(fd);
}
