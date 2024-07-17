/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_goblin_position.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:33:17 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/17 15:00:13 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	ft_helper(t_game *game, int opt)
{
	if (opt == 2)
	{
		if (game->map->map[game->goblin->y - 1][game->goblin->x] == '1')
			opt = 3;
		else
		{
			game->map->map[game->goblin->y - 1][game->goblin->x] = 'M';
			game->goblin->y--;
		}
	}
	if (opt == 3)
	{
		if (game->map->map[game->goblin->y][game->goblin->x - 1] == '1')
			opt = 0;
		else
		{
			game->map->map[game->goblin->y][game->goblin->x - 1] = 'M';
			game->goblin->x--;
		}
	}
}

static void	ft_write_goblin(t_game *game, int opt)
{
	game->map->map[game->goblin->y][game->goblin->x] = '0';
	if (!opt)
	{
		if (game->map->map[game->goblin->y + 1][game->goblin->x] == '1')
			opt = 1;
		else
		{
			game->map->map[game->goblin->y + 1][game->goblin->x] = 'M';
			game->goblin->y++;
		}
	}
	if (opt == 1)
	{
		if (game->map->map[game->goblin->y][game->goblin->x + 1] == '1')
			opt = 2;
		else
		{
		game->map->map[game->goblin->y][game->goblin->x + 1] = 'M';
		game->goblin->x++;
		}
	}
	ft_helper(game, opt);
	game->goblin->moves++;
}

void	ft_update_goblin_position(t_game *game)
{
	if (!game->m)
		return ;
	if (!game->goblin->moves)
		ft_write_goblin(game, 0);
	else if (game->goblin->moves == 1)
		ft_write_goblin(game, 1);
	else if (game->goblin->moves == 2)
		ft_write_goblin(game, 2);
	else
	{
		ft_write_goblin(game, 3);
		game->goblin->moves = 0;
	}
}
