/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_player_move.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:14:02 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 12:32:29 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_update_player_move(t_game *game, const char *tilename, bool render)
{
	int	x;
	int	y;

	ft_put_tile_to_buffer(game, tilename, game->player->y, game->player->x);
	if (!game->map->c_count)
	{
		y = 0;
		while (y < game->map->height)
		{
			x = 0;
			while (x < game->map->width)
			{
				if (game->map->map[y][x] == 'E')
					ft_put_tile_to_buffer(game, "door_open", y, x);
				x++;
			}
			y++;
		}
		game->map->c_count--;
	}
	if (render == true)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->buffer->img_ptr, 0, 0);
		ft_render_info(game);
	}
}
