/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:52:38 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/10 15:04:26 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_render_map(t_game *game)
{
	int	x;
	int	y;

	ft_load_frame(game);
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
						game->wall.img_ptr, x * TILE_SIZE_X, y * TILE_SIZE_Y);
			else if (game->map->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
						game->door.img_ptr, x * TILE_SIZE_X , y * TILE_SIZE_Y);
			else 
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
						game->floor.img_ptr, x * TILE_SIZE_X, y * TILE_SIZE_Y);
			x++;
		}
		y++;
	}
}
