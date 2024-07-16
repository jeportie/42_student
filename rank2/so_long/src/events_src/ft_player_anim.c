/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_anim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:26:29 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/16 19:51:07 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	ft_move(t_game *game, int y_offset, int x_offset)
{
	if (game->map->map[game->orc->y + y_offset * 3][game->orc->x + x_offset * 3]
		!= '1')
	{
		if (game->map->map[game->orc->y + y_offset][game->orc->x + x_offset]
			== 'C')
			game->orc->on_exit = 1;
		game->map->map[game->orc->y + y_offset][game->orc->x + x_offset] = 'M';
		game->orc->y += y_offset;
		game->orc->x += x_offset;
	}
	else
		return (0);
	return (1);
}

void	ft_update_orc_position(t_game *game)
{
	static int	opt = 0;

	if (opt == 0 && !ft_move(game, -1, 0))
	{
		opt++;
		ft_update_orc_position(game);
	}
	if (opt == 1 && !ft_move(game, 0, -1))
	{
		opt++;
		ft_update_orc_position(game);
	}
	if (opt == 2 && !ft_move(game, 1, 0))
	{
		opt++;
		ft_update_orc_position(game);
	}
	if (opt == 3 && !ft_move(game, 0, 1))
	{
		opt = 0;
		ft_update_orc_position(game);
	}
	game->orc->moves++;
}

void	ft_move_orc(t_game *game)
{
	ft_update_orc_move(game, "floor_1", false);
	ft_update_orc_position(game);
	ft_update_orc_move(game, "1n", true);
}

int	ft_player_anim(t_game *game)
{
	static long	count = 1000;
	static long	speed = 1800;

	count--;
	speed--;
	ft_check_exit(game, game->player->y, game->player->x);
	if (!count)
	{
		ft_render_player_anim(game);
		ft_render_goblin_anim(game);
		ft_render_orc_anim(game);
		count = 1000;
	}
	if (!speed)
	{
		ft_move_orc(game);
		speed = 1500;
	}
	return (0);
}
