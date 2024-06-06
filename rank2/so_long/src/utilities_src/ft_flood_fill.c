/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:07:49 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/06 01:58:53 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_flood_fill(t_game *data, int x, int y)
{
	if (x < 0 || x >= data->map->width || y < 0 || y >= data->map->height
		|| data->map->map[y][x] == '1' || data->map->map[y][x] == 'F')
		return ;
	data->map->map[y][x] = 'F';
	ft_flood_fill(data, x + 1, y);
	ft_flood_fill(data, x - 1, y);
	ft_flood_fill(data, x, y + 1);
	ft_flood_fill(data, x, y - 1);
}
