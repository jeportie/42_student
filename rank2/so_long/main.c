/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:57:08 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/21 16:36:40 by jeportie         ###   ########.fr       */
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
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, title);
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
	ft_parse_map(game, mapfile);
	ft_start_display(game, "SO_LONG");
	ft_load_tileset(game, "assets/tileset/tileset.xpm"); 
}

void	ft_print_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			printf("%c", game->map->map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
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
