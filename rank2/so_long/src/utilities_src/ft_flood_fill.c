/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:07:49 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/03 19:08:26 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_flood_fill(t_map *data, int x, int y)
{
	if (x < 0 || x >= data->width || y < 0 || y >= data->height
		|| data->map[x][y] == '1' || data->map[x][y] == 'F')
		return ;
	data->map[x][y] = 'F';
	ft_flood_fill(data, x + 1, y);
	ft_flood_fill(data, x - 1, y);
	ft_flood_fill(data, x, y + 1);
	ft_flood_fill(data, x, y - 1);
}
