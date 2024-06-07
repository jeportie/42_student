/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 00:51:27 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/07 15:25:46 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_read_map(char *filename, t_game *data)
{
	ft_memset(data, 0, sizeof(t_map));
	data->map->height = ft_count_lines(filename);
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
		errno = ENOENT;
		ft_exit_failure(NULL, ENOENT);
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

void	ft_allocate_map(t_game *data)
{
	data->map->map = gc_malloc(sizeof (char *) * (data->map->height + 1));
	if (!data->map)
	{
		errno = ENOMEM;
		ft_exit_failure(data, ENOMEM);
	}
}
//Needs to be freed

void	ft_store_map(char *filename, t_game *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		errno = ENOENT;
		ft_exit_failure(data, ENOENT);
	}
	line = get_next_line(fd);
	gc_register(line);
	while (line)
	{
		data->map->map[i++] = line;
		line = get_next_line(fd);
		gc_register(line);
	}
	data->map->map[i] = NULL;
	close(fd);
}
