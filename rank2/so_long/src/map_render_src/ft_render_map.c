/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:26:09 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/21 18:22:33 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_tile	*ft_get_tile(t_game *game, const char *filename)
{
	int	i;

	i = 0;
	while (i < game->tilecount)
	{
		if (ft_strncmp(game->tiles[i]->name, filename,
				ft_strlen(filename)) == 0)
			return (game->tiles[i]);
		i++;
	}
	return (NULL);
}

void	ft_put_image(t_game *game, const char *tilename, int y, int x)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		ft_get_tile(game, tilename)->img->img_ptr,
		x * MAP_TILE_SIZE,
		y * MAP_TILE_SIZE);
}

void	ft_render_map(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == '1')
				ft_put_image(game, "wall_mid", y, x);
			else 
				ft_put_image(game, "floor_1", y, x);
			x++;
		}
		y++;
	}
}

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
			if (game->map->map[y][x] == 'P')
			{
				ft_blend_images(ft_get_tile(game, "player_f")->img, ft_get_tile(game, "back")->img);
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					ft_get_tile(game, "back")->img->img_ptr,
					x * MAP_TILE_SIZE,
					y * MAP_TILE_SIZE - 2);
			}
			else if (game->map->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					ft_get_tile(game, "coin_anim_f0")->img->img_ptr,
					x * MAP_TILE_SIZE + 5,
					y * MAP_TILE_SIZE + 4);
			else if (game->map->map[y][x] == 'E')
			{
				if (!game->map->c_count)
					ft_put_image(game, "doors_leaf_open", y, x);
				else
					ft_put_image(game, "doors_leaf_closed", y, x);
			}	
			x++;
		}
		y++;
	}
}

void	ft_render_game(t_game *game)
{
	ft_render_map(game);
	ft_render_obj(game);
}
