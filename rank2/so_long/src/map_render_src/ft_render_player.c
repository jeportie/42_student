/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:25:34 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/04 11:12:11 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_render_player(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == 'P')
				ft_put_tile_to_buffer(game, "1b", y, x);
			else if (game->map->map[y][x] == 'M')
				ft_put_tile_to_buffer(game, "1m", y, x);
			else if (game->map->map[y][x] == 'N')
				ft_put_tile_to_buffer(game, "1n", y, x);
			x++;
		}
		y++;
	}
}
