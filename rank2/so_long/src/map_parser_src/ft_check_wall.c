/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:44:08 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 12:45:28 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_check_wall(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		if (game->map->map[y][0] != '1'
			|| game->map->map[y][game->map->width - 1] != '1')
			ft_exit_failure(game, ENOWALLS);
		y++;
	}
	x = 0;
	while (x < game->map->width)
	{
		if (game->map->map[0][x] != '1'
			|| game->map->map[game->map->height - 1][x] != '1')
			ft_exit_failure(game, ENOWALLS);
		x++;
	}
}
