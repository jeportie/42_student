/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_anim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:26:29 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/05 09:13:26 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_update_orc_position(t_game *game)
{
	static int	opt = 0;

	if (!opt)
	{
		if (game->map->map[game->orc->y + 3][game->orc->x] != '1')
		{
			if (game->map->map[game->orc->y + 1][game->orc->x] == 'C')
				game->orc->on_exit = 1;
			game->map->map[game->orc->y + 1][game->orc->x] = 'M';
			game->orc->y++;
		}
		else
		{
			opt++;
			ft_update_orc_position(game);
		}
	}
	else if (opt == 1)
	{
		if (game->map->map[game->orc->y][game->orc->x + 3] != '1')
		{
			if (game->map->map[game->orc->y][game->orc->x + 1] == 'C')
				game->orc->on_exit = 1;
			game->map->map[game->orc->y][game->orc->x + 1] = 'M';
			game->orc->x++;
		}
		else
		{
			opt++;
			ft_update_orc_position(game);
		}
	}
	else if (opt == 2)
	{
		if (game->map->map[game->orc->y - 3][game->orc->x] != '1')
		{
			if (game->map->map[game->orc->y - 1][game->orc->x] == 'C')
				game->orc->on_exit = 1;
			game->map->map[game->orc->y - 1][game->orc->x] = 'M';
			game->orc->y--;
		}
		else
		{
			opt++;
			ft_update_orc_position(game);
		}
	}
	else if (opt == 3)
	{
		if (game->map->map[game->orc->y][game->orc->x - 3] != '1')
		{
			if (game->map->map[game->orc->y][game->orc->x - 1] == 'C')
				game->orc->on_exit = 1;
			game->map->map[game->orc->y][game->orc->x - 1] = 'M';
			game->orc->x--;
		}
		else
		{
			opt = 0;
			ft_update_orc_position(game);
		}
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
		speed = 3500;
	}
	return (0);
}
