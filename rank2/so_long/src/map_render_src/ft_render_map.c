/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:26:09 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/25 17:42:41 by jeportie         ###   ########.fr       */
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

void ft_put_tile_to_buffer(t_game *game, const char *tilename, int y, int x)
{
    t_tile *tile = ft_get_tile(game, tilename);
    if (!tile || !tile->img)
        return;

    char *src_data = tile->img->img_data;
    char *dest_data = game->buffer->img_data;
    int src_line_size = tile->img->size_line;
    int dest_line_size = game->buffer->size_line;
    int bpp = tile->img->bpp / 8;
    int i = 0, j;

    while (i < tile->width)
    {
        j = 0;
        while (j < tile->height)
        {
            *(unsigned int *)(dest_data + ((y * 16 + i) * dest_line_size) + ((x * 16 + j) * bpp)) =
            *(unsigned int *)(src_data + (i * src_line_size) + (j * bpp));
            j++;
        }
        i++;
    }
}

void ft_put_tile_to_buffer_offset(t_game *game, const char *tilename, int y, int x, int offset_y, int offset_x)
{
    t_tile *tile = ft_get_tile(game, tilename);
    if (!tile || !tile->img)
        return;

    char *src_data = tile->img->img_data;
    char *dest_data = game->buffer->img_data;
    int src_line_size = tile->img->size_line;
    int dest_line_size = game->buffer->size_line;
    int bpp = tile->img->bpp / 8;
    int i = 0, j;

    while (i < tile->width)
    {
        j = 0;
        while (j < tile->height)
        {
            *(unsigned int *)(dest_data + ((y * 16 + i + offset_y) * dest_line_size) + ((x * 16 + j + offset_x) * bpp)) =
            *(unsigned int *)(src_data + (i * src_line_size) + (j * bpp));
            j++;
        }
        i++;
    }
}

void ft_clear_buffer(char *img_data, int bpp, int size_line)
{
    int x, y;
    int pixel_bytes = bpp / 8;
    unsigned int color = 0x000000; // Black color

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            *(unsigned int *)(img_data + (y * size_line) + (x * pixel_bytes)) = color;
            x++;
        }
        y++;
    }
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
				ft_put_tile_to_buffer(game, "wall_mid", y, x);
			else if (game->map->map[y][x] == '0' || game->map->map[y][x] == 'C' || game->map->map[y][x] == 'P' ) 
				ft_put_tile_to_buffer(game, "floor_1", y, x);
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
			if (game->map->map[y][x] == 'C')
			{
   //             ft_blend_images(ft_get_tile(game, "coin")->img, ft_get_tile(game, "bcoin")->img);
				ft_put_tile_to_buffer_offset(game, "coin", y, x, 4, 5);
			}
			else if (game->map->map[y][x] == 'E')
			{
				if (!game->map->c_count)
				{
	//				ft_blend_images(ft_get_tile(game, "door_open")->img, ft_get_tile(game, "doback")->img);
					ft_put_tile_to_buffer(game, "door_open", y, x);
				}
				else
				{
	//				ft_blend_images(ft_get_tile(game, "door_closed")->img, ft_get_tile(game, "dcback")->img);
					ft_put_tile_to_buffer(game, "door_closed", y, x);
				}
			}	
			x++;
		}
		y++;
	}
}

void	ft_render_player(t_game *game)
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
				ft_put_tile_to_buffer(game, "back", y, x);
			}
			x++;
		}
		y++;
	}

}

void	ft_render_game(t_game *game)
{
//	ft_clear_buffer(game->buffer->img_data, game->buffer->bpp, game->buffer->size_line);

	ft_render_map(game);
	ft_render_obj(game);
	ft_render_player(game);

	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->buffer->img_ptr, 0, 0);
}
