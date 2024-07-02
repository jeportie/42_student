/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_door.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:40:49 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 12:41:46 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_check_door(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (game->map->map[y][x] != '\n')
		{
			if (game->map->map[y][x] == 'E')
			{
				if (game->map->map[y + 1][x] != '0'
						|| game->map->map[y][x + 1] != '0'
						|| game->map->map[y + 1][x + 1] != '0')
					ft_exit_failure(game, ENODOOR);
			}
			x++;
		}
		y++;
	}
}
