/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_tiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:29:52 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 10:30:13 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	gc_destroy_tiles(t_game *game)
{
	int	i;

	if (!game || !game->tiles)
		return ;
	i = 0;
	while (i < game->tilecount)
	{
		if (game->tiles[i] && game->tiles[i]->img->img_ptr)
			mlx_destroy_image(game->mlx_ptr, game->tiles[i]->img->img_ptr);
		i++;
	}
}

void	gc_destroy_tileset(t_game *game)
{
	if (!game || !game->tileset)
		return ;
	mlx_destroy_image(game->mlx_ptr, game->tileset->img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->buffer->img_ptr);
}
