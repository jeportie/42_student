/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:24:49 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 15:25:13 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

//attention segfault si nom du tiles existe pas -> proteger ca
void	ft_render_obj(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == 'C')
				ft_put_tile_to_buffer_offset(game, "coin", y, x, 4, 5);
			else if (game->map->map[y][x] == 'E')
			{
				if (!game->map->c_count)
					ft_put_tile_to_buffer(game, "door_open", y, x);
				else
					ft_put_tile_to_buffer(game, "door_closed", y, x);
			}	
			x++;
		}
		y++;
	}
}
