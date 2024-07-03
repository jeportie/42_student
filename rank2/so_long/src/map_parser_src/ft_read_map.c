/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 00:51:27 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 14:14:52 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	ft_allocate_map(t_game *game)
{
	game->map->map = gc_malloc(sizeof (char *) * (game->map->height + 1));
	if (!game->map)
	{
		errno = ENOMEM;
		ft_exit_failure(game, ENOMEM);
	}
}

static void	ft_store_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	gc_fd_register(fd);
	if (fd < 0)
	{
		errno = ENOENT;
		ft_exit_failure(game, ENOENT);
	}
	line = get_next_line(fd);
	gc_register(line);
	while (line)
	{
		game->map->map[i++] = line;
		line = get_next_line(fd);
		gc_register(line);
	}
	game->map->map[i] = NULL;
}

void	ft_read_map(char *filename, t_game *game)
{
	ft_memset(game, 0, sizeof(t_map));
	game->map->height = ft_count_lines(filename);
	ft_allocate_map(game);
	ft_store_map(filename, game);
}
