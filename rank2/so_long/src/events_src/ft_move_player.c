/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:11:49 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 12:12:29 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_move_player(int keysym, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player->x;
	new_y = game->player->y;
	ft_update_position(keysym, &new_y, &new_x);
	if (game->map->map[new_y][new_x] != '1')
	{
		ft_check_exit(game, new_y, new_x);
		ft_update_player_move(game, "floor_1", false);
		ft_update_goblin_move(game, "floor_1", false);
		game->player->x = new_x;
		game->player->y = new_y;
		game->map->map[new_y][new_x] = 'P';
		game->player->moves++;
		ft_update_player_move(game, "back", true);
		ft_update_goblin_position(game);
		ft_update_goblin_move(game, "mback", true);
	}
}
