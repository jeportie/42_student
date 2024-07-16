/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 00:51:27 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/16 19:08:22 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	check_fd(t_game *game, int fd)
{
	if (fd < 0)
	{
		errno = ENOENT;
		ft_putstr_fd("Map file not found\n", 2);
		ft_exit_failure(game, ENOENT);
	}
}

static void	ft_allocate_map(t_game *game)
{
	game->map->map = gc_malloc(sizeof (char *) * (game->map->height + 1));
	if (!game->map->map)
	{
		errno = ENOMEM;
		ft_exit_failure(game, ENOMEM);
	}
	gc_lock(game->map->map);
}

void	ft_read_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	ft_memset(game, 0, sizeof(t_map));
	i = 0;
	fd = open(filename, O_RDONLY);
	check_fd(game, fd);
	gc_fd_register(fd);
	game->map->height = ft_count_lines(filename);
	ft_allocate_map(game);
	line = get_next_line(fd);
	gc_register(line);
	gc_lock(line);
	while (line)
	{
		game->map->map[i++] = line;
		line = get_next_line(fd);
		gc_register(line);
		gc_lock(line);
	}
	game->map->map[i] = NULL;
}
