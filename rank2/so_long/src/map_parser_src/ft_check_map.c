/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 01:57:00 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/03 18:54:47 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_free_map(t_map *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (i < data->height)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	free(data);
}

void	ft_check_char(t_map *data, int x, int y)
{
	if (!ft_strchr("01CEP", data->map[x][y]))
		ft_exit_failure(data, ENOCHAR);
	if (data->map[x][y] == 'C')
		data->collectible_count++;
	if (data->map[x][y] == 'E')
	{
		if (data->exit_count)
			ft_exit_failure(data, ENOEXIT);
		data->exit_count++;
	}
	if (data->map[x][y] == 'P')
	{
		if (data->player_count)
			ft_exit_failure(data, ENOSTART);
		data->player_count++;
		data->player_x = x;
		data->player_y = y;
	}
}

void	ft_check_rectangle(t_map *data)
{
	int	width;
	int	i;

	width = ft_strlen(data->map[0]);
	i = 0;
	while (i < data->height)
	{
		if (ft_strlen(data->map[i]) != width)
			ft_exit_failure(data, ENORECT);
		i++;
	}
	data->width = width;
}

void	ft_check_fill(t_map *data)
{
	int	x;
	int	y;

	ft_flood_fill(data, data->player_x, data->player_y);
	x = 0;
	while (x < data->width)
	{
		y = 0;
		while (y < data->height)
		{
			if (data->map[x][y] == '0' || data->map[x][y] == 'C'
				|| data->map[x][y] == 'E')
				ft_exit_failure(data, ENOWALLS);
			y++;
		}
		x++;
	}
}

void	ft_check_map(t_map *data)
{
	int		x;
	int		y;

	data->player_x = -1;
	data->player_y = -1;
	x = 0;
	while (x < data->height)
	{
		y = 0;
		while (data->map[x][y])
		{
			ft_check_char(data, x, y);
			y++;
		}
		x++;
	}
	if (!data->collectible_count)
		ft_exit_failure(data, ENOCOL);
	if (!data->exit_count)
		ft_exit_failure(data, ENOEXIT2);
	if (!data->player_count)
		ft_exit_failure(data, ENOSTART2);
	ft_check_rectangle(data);
	ft_check_fill(data);
}
