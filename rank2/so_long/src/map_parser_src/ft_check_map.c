/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 01:57:00 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/07 15:06:19 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_check_char(t_game *data, int x, int y)
{
	if (!ft_strchr("01CEP", data->map->map[y][x]))
	{
		printf("map[%d][%d] = %c\n", y, x, data->map->map[y][x]);
		ft_exit_failure(data, ENOCHAR);
	}
	if (data->map->map[y][x] == 'C')
		data->map->collectible_count++;
	if (data->map->map[y][x] == 'E')
	{
		if (data->map->exit_count)
			ft_exit_failure(data, ENOEXIT);
		data->map->exit_count++;
	}
	if (data->map->map[y][x] == 'P')
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
	data->map->width = width - 1;
}

char	**ft_duplicate_map(t_map *map)
{
	int		y;
	char	**dup_map;

	dup_map = gc_malloc(sizeof(char *) * (map->height + 1));
	if (!dup_map)
		return (NULL);
	y = 0;
	while (y < map->height)
	{
		dup_map[y] = ft_strdup(map->map[y]);
		gc_register(dup_map[y]);
		if (!dup_map[y])
		{
			while (y-- > 0)
				free(dup_map[y]);
			free(dup_map);
			return (NULL);
		}
		y++;
	}
	dup_map[y] = NULL;
	return (dup_map);
}

//Attention, la premiere map avec pleins de F n'est pas free !
void	ft_check_fill(t_game *data)
{
	int		x;
	int		y;
	char	**dup_map;

	dup_map = ft_duplicate_map(data->map);
	ft_flood_fill(data, data->map->player_x, data->map->player_y);
	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (data->map->map[y][x] == '0' || data->map->map[y][x] == 'C'
				|| data->map->map[y][x] == 'E')
				ft_exit_failure(data, ENOPATH);
			x++;
		}
		y++;
	}
	data->map->map = dup_map;
}

void	ft_check_wall(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->height)
	{
		if (data->map->map[y][0] != '1'
			|| data->map->map[y][data->map->width - 1] != '1')
			ft_exit_failure(data, ENOWALLS);
		y++;
	}
	x = 0;
	while (x < data->map->width)
	{
		if (data->map->map[0][x] != '1'
			|| data->map->map[data->map->height - 1][x] != '1')
			ft_exit_failure(data, ENOWALLS);
		x++;
	}
}

void	ft_check_map(t_game *data)
{
	int		x;
	int		y;

	data->map->exit_count = 0;
	data->map->player_count = 0;
	data->map->collectible_count = 0;
	data->map->player_x = -1;
	data->map->player_y = -1;
	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (data->map->map[y][x] != '\n')
		{
			if (y == data->map->height - 1 && !data->map->map[y][x])
				break ;
			ft_check_char(data, x, y);
			x++;
		}
		y++;
	}
	if (!data->map->collectible_count)
		ft_exit_failure(data, ENOCOL);
	if (!data->map->exit_count)
		ft_exit_failure(data, ENOEXIT2);
	if (!data->map->player_count)
		ft_exit_failure(data, ENOSTART2);
	ft_check_rectangle(data);
	ft_check_fill(data);
	ft_check_wall(data);
}
