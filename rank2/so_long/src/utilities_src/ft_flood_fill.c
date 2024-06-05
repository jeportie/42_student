/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:07:49 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/06 00:15:51 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_flood_fill(t_game *data, int x, int y)
{
	if (x < 0 || x >= data->map->width || y < 0 || y >= data->map->height
		|| data->map->map[x][y] == '1' || data->map->map[x][y] == 'F')
		return ;
	data->map->map[x][y] = 'F';
	ft_flood_fill(data, x + 1, y);
	ft_flood_fill(data, x - 1, y);
	ft_flood_fill(data, x, y + 1);
	ft_flood_fill(data, x, y - 1);
}
