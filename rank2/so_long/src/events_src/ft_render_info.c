/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:28:17 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 12:28:17 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_render_info(t_game *game)
{
	char	*moves;
	char	*old_moves;
	int		nbr;

	nbr = game->player->moves;
	moves = ft_itoa(nbr);
	gc_register(moves);
	if (!moves)
		ft_exit_failure(game, ENOMEM);
	old_moves = ft_itoa(nbr - 1);
	gc_register(old_moves);
	if (!moves)
		ft_exit_failure(game, ENOMEM);
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		(game->map->width / 2 - 3) * MAP_TILE_SIZE,
		game->map->height * MAP_TILE_SIZE + 20, 0xFFFFFF, "Total Moves:");
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		(game->map->width / 2 + 2) * MAP_TILE_SIZE,
		game->map->height * MAP_TILE_SIZE + 20, 0x000000, old_moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		(game->map->width / 2 + 2) * MAP_TILE_SIZE,
		game->map->height * MAP_TILE_SIZE + 20, 0xFFFFFF, moves);
}
