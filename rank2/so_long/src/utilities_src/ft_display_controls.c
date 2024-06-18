/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_controls.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:44:18 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/19 00:30:41 by jeportie         ###   ########.fr       */
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
	game->map->exit_count = count;
	return (count);
}

int	ft_display_controls(int keysym, t_game *data)
{
	int new_x = data->map->player_x;
	int new_y = data->map->player_y;

	if (keysym == XK_w || keysym == XK_Up)
		new_y--;
	else if (keysym == XK_s || keysym == XK_Down)
		new_y++;
	else if (keysym == XK_a || keysym == XK_Left)
		new_x--;
	else if (keysym == XK_d || keysym == XK_Right)
		new_x++;
	if (data->map->map[new_y][new_x] != '1')
	{
		if (data->map->map[new_y][new_x] == 'C')
			data->map->collectible_count++;
		data->map->map[data->map->player_y][data->map->player_x] = '0';
		data->map->player_x = new_x;
		data->map->player_y = new_y;
		data->map->map[new_y][new_x] = 'P';
		data->map->player_count++;
		ft_render_game(data);
	}

	if (keysym == XK_Escape)
	{
		gc_destroy_tiles(data);
		gc_destroy_tileset(data);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		gc_cleanup();
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	ft_close_window(t_game *data)
{
	gc_destroy_tiles(data);
	gc_destroy_tileset(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	gc_cleanup();
	exit(EXIT_SUCCESS);
	return (0);
}
