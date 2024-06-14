/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:52:38 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/14 16:43:01 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_render_map(t_game *game)
{
	int		x;
	int		y;
	t_img	floor;
	t_img	wall;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
						&wall.img_ptr, x * TILE_SIZE_X, y * TILE_SIZE_Y);
			else 
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
						&floor.img_ptr, x * TILE_SIZE_X, y * TILE_SIZE_Y);
			x++;
		}
		y++;
	}
}
