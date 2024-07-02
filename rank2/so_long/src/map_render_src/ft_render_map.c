/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:26:09 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 15:26:22 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_render_map(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == '1')
				ft_put_tile_to_buffer(game, "wall_mid", y, x);
			else if (game->map->map[y][x] == '0' || game->map->map[y][x] == 'C'
				|| game->map->map[y][x] == 'P' )
				ft_put_tile_to_buffer(game, "floor_1", y, x);
			x++;
		}
		y++;
	}
}
