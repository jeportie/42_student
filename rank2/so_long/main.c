/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:57:08 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/17 18:58:28 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include <X11/keysym.h>
#include <X11/X.h>

void	ft_start_display(t_game *data, char *title)
{
	data->mlx_ptr = mlx_init();
	gc_register(data->mlx_ptr);
	if (!data->mlx_ptr)
		ft_exit_failure(data, ENOINIT);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->map->width * TILE_SIZE_X,
			data->map->height * TILE_SIZE_Y, title);
	if (!data->win_ptr)
		ft_exit_failure(data, ENOWIN);
}

int	main(int argc, char **argv)
{
	t_game	game = {0};

	if (argc != 2)
		ft_exit_failure(&game, ENOFORMAT);
	ft_parse_map(&game, argv[1]);
	ft_start_display(&game, "SO_LONG");
	ft_load_tileset(&game, "assets/tileset/tileset.xpm"); 
	ft_parse_tileset(&game, "assets/tileset/tile_list");
	ft_render_map(&game);

	mlx_hook(game.win_ptr, 17, 0, ft_close_window, &game);
	mlx_key_hook(game.win_ptr, ft_display_controls, &game);

	mlx_loop(game.mlx_ptr);

	return (0);
}
