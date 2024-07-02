/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 01:57:00 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 12:52:48 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	ft_init_map(t_game *game)
{
	game->map->e_count = 0;
	game->map->p_count = 0;
	game->map->c_count = 0;
	game->player->x = -1;
	game->player->y = -1;
}

static void	ft_checker_map(t_game *game)
{
	if (!game->map->c_count)
		ft_exit_failure(game, ENOCOL);
	if (!game->map->e_count)
		ft_exit_failure(game, ENOEXIT2);
	if (!game->map->p_count)
		ft_exit_failure(game, ENOSTART2);
	ft_check_rectangle(game);
	ft_check_fill(game);
	ft_check_wall(game);
	ft_check_door(game);
}

void	ft_check_map(t_game *game)
{
	int		x;
	int		y;

	ft_init_map(game);
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (game->map->map[y][x] != '\n')
		{
			if (y == game->map->height - 1 && !game->map->map[y][x])
				break ;
			ft_check_char(game, x, y);
			x++;
		}
		y++;
	}
	ft_checker_map(game);
}
