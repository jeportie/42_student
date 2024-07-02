/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_goblin_move.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:32:07 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 12:32:07 by jeportie         ###   ########.fr       */
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
