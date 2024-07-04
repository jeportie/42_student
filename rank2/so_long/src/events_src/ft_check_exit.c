/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:09:02 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/04 14:42:15 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_check_exit(t_game *game, int new_y, int new_x)
{
	if ((game->player->x == game->goblin->x
			&& game->player->y == game->goblin->y)
		|| (game->player->x == game->orc->x
			&& game->player->y == game->orc->y))
		ft_close_game(game);
	if (game->map->c_count <= 0 && (game->map->map[new_y][new_x] == 'E'
		|| game->map->map[new_y][new_x - 1] == 'E'
		|| game->map->map[new_y - 1][new_x] == 'E'
		|| game->map->map[new_y - 1][new_x - 1] == 'E'))
		ft_close_game(game);
	if (game->map->map[new_y][new_x] == 'C')
		game->map->c_count--;
	if (game->on_exit == true)
	{
		game->map->map[game->player->y][game->player->x] = 'E';
		game->on_exit = false;
	}
	else
		game->map->map[game->player->y][game->player->x] = '0';
	if (game->map->map[new_y][new_x] == 'E')
		game->on_exit = true;
}
