/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:41:59 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 12:43:35 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static char	**ft_duplicate_map(t_map *map)
{
	int		y;
	char	**dup_map;

	dup_map = gc_malloc(sizeof(char *) * (map->height + 1));
	if (!dup_map)
		return (NULL);
	y = 0;
	while (y < map->height)
	{
		dup_map[y] = ft_strdup(map->map[y]);
		gc_register(dup_map[y]);
		if (!dup_map[y])
		{
			while (y-- > 0)
				free(dup_map[y]);
			free(dup_map);
			return (NULL);
		}
		y++;
	}
	dup_map[y] = NULL;
	return (dup_map);
}

void	ft_check_fill(t_game *game)
{
	int		x;
	int		y;
	char	**dup_map;

	dup_map = ft_duplicate_map(game->map);
	ft_flood_fill(game, game->player->x, game->player->y);
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == '0' || game->map->map[y][x] == 'C'
				|| game->map->map[y][x] == 'E')
				ft_exit_failure(game, ENOPATH);
			x++;
		}
		y++;
	}
	game->map->map = dup_map;
}
