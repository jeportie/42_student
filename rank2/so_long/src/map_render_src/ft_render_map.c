/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:52:38 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/19 00:09:25 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	*ft_get_tile(t_game *game, const char *tile_name)
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

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					ft_get_tile(game, "wall_mid"), x * TILE_SIZE_X, y * TILE_SIZE_Y);
			else 
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					ft_get_tile(game, "floor_1"), x * TILE_SIZE_X, y * TILE_SIZE_Y);
			x++;
		}
		y++;
	}
}

void	ft_render_obj(t_game *game)
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
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					ft_get_tile(game, "knight_f_idle_anim_f0"), x * 16, y * 16);
			}
			else if (game->map->map[y][x] == 'C')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					ft_get_tile(game, "coin_anim_f0"), x * TILE_SIZE_X, y * TILE_SIZE_Y);
			}
			else if (game->map->map[y][x] == 'E')
			{
				if (!game->map->collectible_count)
					mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
						ft_get_tile(game, "doors_leaf_open"), x * TILE_SIZE_X, y * TILE_SIZE_Y);
				else
					mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
						ft_get_tile(game, "doors_leaf_closed"), x * TILE_SIZE_X, y * TILE_SIZE_Y);
			}	
			x++;
		}
		y++;
	}
}

void	ft_render_game(t_game *game)
{
	ft_render_map(game);
	ft_render_obj(game);
}
