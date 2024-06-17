/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:52:38 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/17 18:51:52 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	*get_tile_image(t_game *game, const char *tile_name)
{
	int i;

	for (i = 0; i < game->tilecount; i++)
	{
		if (ft_strncmp(game->tiles[i]->name, tile_name, ft_strlen(tile_name)) == 0)
		{
			return game->tiles[i]->img.img_ptr;
		}
	}
	return NULL; // Return NULL if the tile is not found
}

void	ft_render_map(t_game *game)
{
	int		x;
	int		y;
	void	*floor_img;
	void	*wall_img;

	floor_img = get_tile_image(game, "floor_1");
	wall_img = get_tile_image(game, "wall_mid");

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == '1')
			{
				if (wall_img)
					mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
						wall_img, x * TILE_SIZE_X, y * TILE_SIZE_Y);
			}
			else 
			{
				if (floor_img)
					mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
						floor_img, x * TILE_SIZE_X, y * TILE_SIZE_Y);
			}
			x++;
		}
		y++;
	}
}
