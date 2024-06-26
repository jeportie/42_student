/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 01:57:00 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/26 11:08:26 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_check_char(t_game *game, int x, int y)
{
	if (!ft_strchr("01CEP", game->map->map[y][x]))
	{
		printf("map[%d][%d] = %c\n", y, x, game->map->map[y][x]);
		ft_exit_failure(game, ENOCHAR);
	}
	if (game->map->map[y][x] == 'C')
		game->map->c_count++;
	if (game->map->map[y][x] == 'E')
	{
		if (game->map->e_count)
			ft_exit_failure(game, ENOEXIT);
		game->map->e_count++;
	}
	if (game->map->map[y][x] == 'P')
	{
		if (game->map->p_count)
			ft_exit_failure(game, ENOSTART);
		game->map->p_count++;
		game->player->x = x;
		game->player->y = y;
	}
}

void	ft_check_rectangle(t_game *game)
{
	int	width;
	int	i;

	width = ft_strlen(game->map->map[0]);
	i = 0;
	while (i < game->map->height)
	{
		if (ft_strlen(game->map->map[i]) != width)
			ft_exit_failure(game, ENORECT);
		i++;
	}
	game->map->width = width - 1;
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

void	ft_check_fill(t_game *game)
{
	int		x;
	int		y;
	char	**dup_map;

	dup_map = ft_duplicate_map(game->map);
	ft_flood_fill(game, game->player->x, game->player->y);
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == '0' || game->map->map[y][x] == 'C'
				|| game->map->map[y][x] == 'E')
				ft_exit_failure(game, ENOPATH);
			x++;
		}
		y++;
	}
	game->map->map = dup_map;
}

void	ft_check_wall(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		if (game->map->map[y][0] != '1'
			|| game->map->map[y][game->map->width - 1] != '1')
			ft_exit_failure(game, ENOWALLS);
		y++;
	}
	x = 0;
	while (x < game->map->width)
	{
		if (game->map->map[0][x] != '1'
			|| game->map->map[game->map->height - 1][x] != '1')
			ft_exit_failure(game, ENOWALLS);
		x++;
	}
}

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
				if (game->map->map[y + 1][x] != '0' || game->map->map[y][x + 1] != '0' || game->map->map[y + 1][x + 1] != '0')
					ft_exit_failure(game, ENODOOR);
			}
			x++;
		}
		y++;
	}
}

void	ft_check_map(t_game *game)
{
	int		x;
	int		y;

	game->map->e_count = 0;
	game->map->p_count = 0;
	game->map->c_count = 0;
	game->player->x = -1;
	game->player->y = -1;
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (game->map->map[y][x] != '\n')
		{
			if (y == game->map->height - 1 && !game->map->map[y][x])
				break ;
			ft_check_char(game, x, y);
			x++;
		}
		y++;
	}
	if (!game->map->c_count)
		ft_exit_failure(game, ENOCOL);
	if (!game->map->e_count)
		ft_exit_failure(game, ENOEXIT2);
	if (!game->map->p_count)
		ft_exit_failure(game, ENOSTART2);
	ft_check_rectangle(game);
	ft_check_fill(game);
	ft_check_wall(game);
	ft_check_door(game);
}
