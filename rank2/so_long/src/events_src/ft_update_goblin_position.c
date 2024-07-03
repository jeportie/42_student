/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_goblin_position.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:33:17 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/03 13:55:35 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	ft_write_goblin(t_game *game, int opt)
{
	game->map->map[game->goblin->y][game->goblin->x] = '0';
	if (!opt)
	{
		game->map->map[game->goblin->y + 1][game->goblin->x] = 'M';
		game->goblin->y++;
	}
	else if (opt == 1)
	{
		game->map->map[game->goblin->y][game->goblin->x + 1] = 'M';
		game->goblin->x++;
	}
	else if (opt == 2)
	{
		game->map->map[game->goblin->y - 1][game->goblin->x] = 'M';
		game->goblin->y--;
	}
	else
	{
		game->map->map[game->goblin->y][game->goblin->x - 1] = 'M';
		game->goblin->x--;
	}
	game->goblin->moves++;
}

void	ft_update_goblin_position(t_game *game)
{
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
