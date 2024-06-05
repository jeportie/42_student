/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 01:57:00 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/05 23:59:57 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_check_char(t_game *data, int x, int y)
{
	if (!ft_strchr("01CEP", data->map->map[x][y]))
		ft_exit_failure(data, ENOCHAR);
	if (data->map->map[x][y] == 'C')
		data->map->collectible_count++;
	if (data->map->map[x][y] == 'E')
	{
		if (data->map->exit_count)
			ft_exit_failure(data, ENOEXIT);
		data->map->exit_count++;
	}
	if (data->map->map[x][y] == 'P')
	{
		if (data->map->player_count)
			ft_exit_failure(data, ENOSTART);
		data->map->player_count++;
		data->map->player_x = x;
		data->map->player_y = y;
	}
}

void	ft_check_rectangle(t_game *data)
{
	int	width;
	int	i;

	width = ft_strlen(data->map->map[0]);
	i = 0;
	while (i < data->map->height)
	{
		if (ft_strlen(data->map->map[i]) != width)
			ft_exit_failure(data, ENORECT);
		i++;
	}
	data->map->width = width;
}

void	ft_check_fill(t_game *data)
{
	int	x;
	int	y;

	ft_flood_fill(data, data->map->player_x, data->map->player_y);
	x = 0;
	while (x < data->map->width)
	{
		y = 0;
		while (y < data->map->height)
		{
			if (data->map->map[x][y] == '0' || data->map->map[x][y] == 'C'
				|| data->map->map[x][y] == 'E')
				ft_exit_failure(data, ENOWALLS);
			y++;
		}
		x++;
	}
}

void	ft_check_map(t_game *data)
{
	int		x;
	int		y;

	data->map->player_x = -1;
	data->map->player_y = -1;
	x = 0;
	while (x < data->map->height)
	{
		y = 0;
		while (data->map->map[x][y])
		{
			ft_check_char(data, x, y);
			y++;
		}
		x++;
	}
	if (!data->map->collectible_count)
		ft_exit_failure(data, ENOCOL);
	if (!data->map->exit_count)
		ft_exit_failure(data, ENOEXIT2);
	if (!data->map->player_count)
		ft_exit_failure(data, ENOSTART2);
	ft_check_rectangle(data);
	ft_check_fill(data);
}
