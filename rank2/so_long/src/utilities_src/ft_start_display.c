/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:07:49 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 11:09:10 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_start_display(t_game *game, char *title)
{
	game->mlx_ptr = mlx_init();
	gc_register(game->mlx_ptr);
	if (!game->mlx_ptr)
		ft_exit_failure(game, ENOINIT);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->map->width * MAP_TILE_SIZE,
			game->map->height * MAP_TILE_SIZE + GAME_BORDER, title);
	if (!game->win_ptr)
		ft_exit_failure(game, ENOWIN);
}
