/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:57:08 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/27 14:14:19 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include <X11/keysym.h>
#include <X11/X.h>

void	ft_start_display(t_game *game, char *title)
{
	game->mlx_ptr = mlx_init();
	gc_register(game->mlx_ptr);
	if (!game->mlx_ptr)
		ft_exit_failure(game, ENOINIT);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->map->width * MAP_TILE_SIZE,
			game->map->height * MAP_TILE_SIZE + 50, title);
	if (!game->win_ptr)
		ft_exit_failure(game, ENOWIN);
}

void	ft_init_game(t_game *game, char *mapfile)
{
	game->player = gc_malloc(sizeof(t_player));
	if (!game->player)
	{
		errno = ENOMEM;
		ft_exit_failure(NULL, ENOMEM);
	}
	game->player->moves = 0;
	game->goblin = gc_malloc(sizeof(t_player));
	if (!game->goblin)
	{
		errno = ENOMEM;
		ft_exit_failure(NULL, ENOMEM);
	}
	game->goblin->moves = 0;
	ft_parse_map(game, mapfile);
	ft_start_display(game, "SO_LONG");
	ft_load_tileset(game, "assets/tileset/tileset.xpm"); 
	game->buffer = gc_malloc(sizeof(t_img));
	if (!game->buffer)
	{
		errno = ENOMEM;
		ft_exit_failure(NULL, ENOMEM);
	}
	game->buffer->img_ptr = mlx_new_image(game->mlx_ptr, game->map->width * MAP_TILE_SIZE,
			game->map->height * MAP_TILE_SIZE);
	if (!game->buffer->img_ptr)
		ft_exit_failure(game, ENOMEM);
	game->buffer->img_data = mlx_get_data_addr(game->buffer->img_ptr,
		&game->buffer->bpp, &game->buffer->size_line, &game->buffer->endian);

}

int	main(int argc, char **argv)
{
	t_game	game = {0};

	if (argc != 2)
		ft_exit_failure(&game, ENOFORMAT);

	ft_init_game(&game, argv[1]);
	ft_render_game(&game);

	mlx_hook(game.win_ptr, 17, 0, ft_close_game, &game);
	mlx_key_hook(game.win_ptr, ft_display_controls, &game);

	mlx_loop(game.mlx_ptr);

	return (0);
}
