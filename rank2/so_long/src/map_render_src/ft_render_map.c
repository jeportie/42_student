/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:52:38 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/05 23:01:28 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_render_map(t_game *game)
{
	int	x;
	int	y;

	ft_load_frame(game);
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[x][y] == '1')
				ft_put_tile(game, &game->wall, x, y);
			else if (game->map->map[x][y] == '0')
				ft_put_tile(game, &game->floor, x, y);
			x++;
		}
		y++;
	}
}
