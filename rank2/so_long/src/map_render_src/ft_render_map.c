/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:26:09 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/27 22:34:30 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"




t_tile	*ft_get_tile(t_game *game, const char *filename)
{
	int	i;

	i = 0;
	while (i < game->tilecount)
	{
		if (!ft_strncmp(game->tiles[i]->name, filename,
				ft_strlen(filename)))
			return (game->tiles[i]);
		i++;
	}
	return (NULL);
}

void ft_put_tile_to_buffer(t_game *game, const char *tilename, int y, int x)
{
    char    *src_data;
    char    *dest_data;
    int     src_line_size;
    int     dest_line_size;
    int     bpp;
    int     i;
    int     j;

    t_tile *tile = ft_get_tile(game, tilename);
    if (!tile || !tile->img)
        ft_exit_failure(game, ENOTILE);

    src_data = tile->img->img_data;
    dest_data = game->buffer->img_data;
    src_line_size = tile->img->size_line;
    dest_line_size = game->buffer->size_line;
    bpp = tile->img->bpp / 8;
    i = 0;
    while (i < tile->width)
    {
        j = 0;
        while (j < tile->height)
        {
            *(unsigned int *)(dest_data + ((y * 16 + j) * dest_line_size)
                    + ((x * 16 + i) * bpp)) =
            *(unsigned int *)(src_data + (j * src_line_size) + (i * bpp));
            j++;
        }
        i++;
    }
}

void ft_put_tile_to_buffer_offset(t_game *game, const char *tilename, int y, int x, int offset_y, int offset_x)
{
    t_tile *tile = ft_get_tile(game, tilename);
    if (!tile || !tile->img)
        ft_exit_failure(game, ENOTILE);

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
            *(unsigned int *)(dest_data + ((y * 16 + i + offset_y) * dest_line_size)
                    + ((x * 16 + j + offset_x) * bpp)) =
            *(unsigned int *)(src_data + (i * src_line_size) + (j * bpp));
            j++;
        }
        i++;
    }
}

void ft_clear_buffer(t_game *game, char *img_data, int bpp, int size_line)
{
    int x, y;
    int pixel_bytes = bpp / 8;
    unsigned int color = 0x000000; // Black color

    y = 0;
    while (y < game->map->height * MAP_TILE_SIZE + 50)
    {
        x = 0;
        while (x < game->map->width * MAP_TILE_SIZE)
        {
            *(unsigned int *)(img_data + (y * size_line)
                    + (x * pixel_bytes)) = color;
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
			else if (game->map->map[y][x] == '0' || game->map->map[y][x] == 'C'
                    || game->map->map[y][x] == 'P' ) 
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
				ft_put_tile_to_buffer_offset(game, "coin", y, x, 4, 5);
			else if (game->map->map[y][x] == 'E')
			{
				if (!game->map->c_count)
					ft_put_tile_to_buffer(game, "door_open", y, x);
				else
					ft_put_tile_to_buffer(game, "door_closed", y, x);
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
				ft_blend_images(ft_get_tile(game, "player_f")->img,
                        ft_get_tile(game, "back")->img);
				ft_put_tile_to_buffer(game, "back", y, x);
			}
            else if (game->map->map[y][x] == 'M')
			{
				ft_blend_images(ft_get_tile(game, "goblin")->img,
                      ft_get_tile(game, "mback")->img);
			ft_put_tile_to_buffer(game, "mback", y, x);
			}
			x++;
		}
		y++;
	}

}

void    ft_init_player_anim(t_game *game)
{
	ft_blend_images(ft_get_tile(game, "knight_f_idle_anim_f0")->img, ft_get_tile(game, "1b")->img);
    ft_blend_images(ft_get_tile(game, "knight_f_idle_anim_f1")->img, ft_get_tile(game, "2b")->img);
    ft_blend_images(ft_get_tile(game, "knight_f_idle_anim_f2")->img, ft_get_tile(game, "3b")->img);
    ft_blend_images(ft_get_tile(game, "knight_f_idle_anim_f3")->img, ft_get_tile(game, "4b")->img);
}

int ft_player_anim(t_game *game)
{
    static long count = 500;
    static int  turn = 0;

    if (game->player->x == game->goblin->x && game->player->y == game->goblin->y)
        ft_close_game(game);
    count--;
    if (!count)
    {
        if (!turn)
        {
            ft_put_tile_to_buffer(game, "1b", game->player->y, game->player->x);
            turn++;
        }
        else if (turn == 1)
        {
            ft_put_tile_to_buffer(game, "2b", game->player->y, game->player->x);
            turn++;
        }
        else if (turn == 2)
        {
            ft_put_tile_to_buffer(game, "3b", game->player->y, game->player->x);
            turn++;
        }
        else if (turn == 3)
        {
            ft_put_tile_to_buffer(game, "3b", game->player->y, game->player->x);
            turn = 0;
        }
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->buffer->img_ptr, 0, 0);
        count = 800;
    }
    return (0);
}

void	ft_update_player_move(t_game *game, const char *tilename, bool render)
{
    int x;
    int y;

    ft_put_tile_to_buffer(game, tilename, game->player->y, game->player->x);
    if (!game->map->c_count)
    {
    	y = 0;
    	while (y < game->map->height)
    	{
    		x = 0;
    		while (x < game->map->width)
    		{
    			if (game->map->map[y][x] == 'E')
                    ft_put_tile_to_buffer(game, "door_open", y, x);
    			x++;
    		}
    		y++;
    	}
        game->map->c_count--;
    }
    if (render == true)
    {
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
                game->buffer->img_ptr, 0, 0);
        ft_render_info(game);
    }
}

void	ft_update_goblin_move(t_game *game, const char *tilename, bool render)
{
    ft_put_tile_to_buffer(game, tilename, game->goblin->y, game->goblin->x);
    if (render == true)
    {
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
                game->buffer->img_ptr, 0, 0);
    }
}

void    ft_render_info(t_game *game)
{
    char    *moves;
    int     nbr;

    nbr = game->player->moves;
    moves = ft_itoa(nbr);
    gc_register(moves);
    if (!moves)
        ft_exit_failure(game, ENOMEM);

    mlx_string_put(game->mlx_ptr, game->win_ptr,
            (game->map->width / 2 - 3) * MAP_TILE_SIZE,
			game->map->height * MAP_TILE_SIZE + 20, 0xFFFFFF, "Total Moves:");

    mlx_string_put(game->mlx_ptr, game->win_ptr,
            (game->map->width / 2 + 2) * MAP_TILE_SIZE,
			game->map->height * MAP_TILE_SIZE + 20, 0xFFFFFF, moves);
}

void	ft_render_game(t_game *game)
{
//	ft_clear_buffer(game->buffer->img_data, game->buffer->bpp, game->buffer->size_line);


    ft_render_map(game);
	ft_render_obj(game);
	ft_render_player(game);

	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->buffer->img_ptr, 0, 0);
    ft_render_info(game);
}
