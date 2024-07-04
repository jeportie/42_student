/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_goblin_move.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:32:07 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/04 19:13:49 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_update_goblin_move(t_game *game, const char *tilename, bool render)
{
	ft_put_tile_to_buffer(game, tilename, game->goblin->y, game->goblin->x);
	if (render == true)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->buffer->img_ptr, 0, 0);
	}
}

void	ft_update_orc_move(t_game *game, const char *tilename, bool render)
{
	ft_put_tile_to_buffer(game, tilename, game->orc->y, game->orc->x);
	if (render == true)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->buffer->img_ptr, 0, 0);
	}
	else
	{
		if (game->orc->on_exit)
			ft_put_tile_to_buffer(game, "coin", game->orc->y, game->orc->x);
		if (game->orc->on_exit)
		{
			game->map->map[game->orc->y][game->orc->x] = 'C';
			game->orc->on_exit = 0;
		}
		else
			game->map->map[game->orc->y][game->orc->x] = '0';
	}
}
