/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:07:49 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/21 14:12:50 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_flood_fill(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map->width || y < 0 || y >= game->map->height
		|| game->map->map[y][x] == '1' || game->map->map[y][x] == 'F')
		return ;
	game->map->map[y][x] = 'F';
	ft_flood_fill(game, x + 1, y);
	ft_flood_fill(game, x - 1, y);
	ft_flood_fill(game, x, y + 1);
	ft_flood_fill(game, x, y - 1);
}
