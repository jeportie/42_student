/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:39:39 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/17 14:53:41 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	ft_update_pos(t_player *type, int x, int y)
{
	type->x = x;
	type->y = y;
}

static void	ft_helper(t_game *game, int x, int y)
{
	if (game->map->map[y][x] == 'M')
	{
		game->m = true;
		ft_update_pos(game->goblin, x, y);
	}
	if (game->map->map[y][x] == 'N')
	{
		game->n = true;
		ft_update_pos(game->orc, x, y);
	}
}

void	ft_check_char(t_game *game, int x, int y)
{
	if (!ft_strchr("01CEPMN", game->map->map[y][x]))
	{
		printf("map[%d][%d] = %c\n", y, x, game->map->map[y][x]);
		ft_exit_failure(game, ENOCHAR);
	}
	if (game->map->map[y][x] == 'C')
		game->map->c_count++;
	if (game->map->map[y][x] == 'E')
	{
		if (game->map->e_count)
			ft_exit_failure(game, ENOEXIT);
		game->map->e_count++;
	}
	if (game->map->map[y][x] == 'P')
	{
		if (game->map->p_count)
			ft_exit_failure(game, ENOSTART);
		game->map->p_count++;
		ft_update_pos(game->player, x, y);
	}
	ft_helper(game, x, y);
}
