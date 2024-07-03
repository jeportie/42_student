/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:09:19 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/03 15:18:07 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	ft_init_objects(t_game *game)
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
}

void	ft_init_game(t_game *game, char *mapfile)
{
	ft_init_objects(game);
	ft_parse_map(game, mapfile);
	ft_start_display(game, "SO_LONG");
	if (!ft_check_tilelist("assets/tileset/tile_list"))
		ft_exit_failure(game, ENOLIST);
	ft_load_tileset(game, "assets/tileset/tileset.xpm");
	ft_init_player_anim(game);
	game->buffer = gc_malloc(sizeof(t_img));
	if (!game->buffer)
	{
		errno = ENOMEM;
		ft_exit_failure(NULL, ENOMEM);
	}
	game->buffer->img_ptr = mlx_new_image(game->mlx_ptr,
			game->map->width * MAP_TILE_SIZE,
			game->map->height * MAP_TILE_SIZE);
	if (!game->buffer->img_ptr)
		ft_exit_failure(game, ENOMEM);
	game->buffer->img_data = mlx_get_data_addr(game->buffer->img_ptr,
			&game->buffer->bpp, &game->buffer->size_line,
			&game->buffer->endian);
}
