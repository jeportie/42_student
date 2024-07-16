/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:09:19 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/16 22:32:26 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	check_malloc(void *ptr)
{
	if (!ptr)
		ft_exit_failure(NULL, ENOMEM);
}

static void	ft_init_objects(t_game *game)
{
	game->player = gc_malloc(sizeof(t_player));
	check_malloc(game->player);
	gc_lock(game->player);
	game->player->moves = 0;
	game->goblin = gc_malloc(sizeof(t_player));
	check_malloc(game->goblin);
	gc_lock(game->goblin);
	game->goblin->moves = 0;
	game->orc = gc_malloc(sizeof(t_player));
	check_malloc(game->orc);
	gc_lock(game->orc);
	game->orc->moves = 0;
	game->orc->on_exit = 0;
}

void	ft_init_game(t_game *game, char *mapfile)
{
	ft_init_objects(game);
	ft_parse_map(game, mapfile);
	ft_start_display(game, "SO_LONG");
	game->state = NO_TILE;
	if (!ft_check_tilelist(game, "assets/tileset/tile_list"))
		ft_exit_failure(game, ENOLIST);
	ft_load_tileset(game, "assets/tileset/tileset.xpm");
	game->state = LOADED;
	ft_init_player_anim(game);
	game->buffer = gc_malloc(sizeof(t_img));
	check_malloc(game->buffer);
	gc_lock(game->buffer);
	game->buffer->img_ptr = mlx_new_image(game->mlx_ptr,
			game->map->width * MAP_TILE_SIZE,
			game->map->height * MAP_TILE_SIZE);
	if (!game->buffer->img_ptr)
		ft_exit_failure(game, ENOMEM);
	game->buffer->img_data = mlx_get_data_addr(game->buffer->img_ptr,
			&game->buffer->bpp, &game->buffer->size_line,
			&game->buffer->endian);
}
