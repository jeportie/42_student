/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_controls.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:44:18 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/26 10:31:12 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include <X11/keysym.h>
#include <X11/X.h>

int	ft_count_collectibles(t_game *game)
{
	int		x;
	int		y;
	int		count;

	y = 0;
	count = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	game->map->e_count = count;
	return (count);
}

void	ft_move_player(int keysym, t_game *game)
{
	int new_x = game->player->x;
	int new_y = game->player->y;

	if (keysym == XK_w || keysym == XK_Up)
		new_y--;
	else if (keysym == XK_s || keysym == XK_Down)
		new_y++;
	else if (keysym == XK_a || keysym == XK_Left)
		new_x--;
	else if (keysym == XK_d || keysym == XK_Right)
		new_x++;
	else
		return ;
	if (game->map->map[new_y][new_x] != '1')
	{
		if (!game->map->c_count && (game->map->map[new_y][new_x] == 'E'
				|| game->map->map[new_y][new_x - 1] == 'E'
				|| game->map->map[new_y - 1][new_x] == 'E'
				|| game->map->map[new_y - 1][new_x - 1] == 'E'))
			ft_close_game(game);

		if (game->map->map[new_y][new_x] == 'C')
			game->map->c_count--;

		if (game->on_exit == true)
		{
			game->map->map[game->player->y][game->player->x] = 'E';
			game->on_exit = false;
		}
		else
			game->map->map[game->player->y][game->player->x] = '0';

		if (game->map->map[new_y][new_x] == 'E')
			game->on_exit = true;

		ft_update_move(game, "floor_1", false);

		game->player->x = new_x;
		game->player->y = new_y;
		game->map->map[new_y][new_x] = 'P';
		game->player->moves++;
		ft_update_move(game, "back", true);
//		ft_render_game(game);
	}
}

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
	gc_collect();
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
