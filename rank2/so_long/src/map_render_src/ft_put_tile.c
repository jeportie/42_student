/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:45:34 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/06 17:08:26 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_put_tile(t_game *game, t_img *tile, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			tile->img_ptr, x * TILE_SIZE_X, y * TILE_SIZE_Y);
}
