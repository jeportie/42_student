/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_controls.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:44:18 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/16 18:19:35 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_display_controls(int keysym, t_game *game)
{
	ft_move_player(keysym, game);
	if (keysym == XK_Escape)
		ft_close_game(game);
	return (0);
}

int	ft_close_window(t_game *game)
{
	gc_destroy_tiles(game);
	gc_destroy_tileset(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	return (0);
}

int	ft_close_game(t_game *game)
{
	gc_destroy_tiles(game);
	gc_destroy_tileset(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	gc_cleanup();
	exit(EXIT_SUCCESS);
	return (0);
}
