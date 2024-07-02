/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:24:54 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 15:24:08 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>
# include <X11/keysym.h>
#include <X11/X.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include "libft.h"
# include "mlx.h"
# include "garbage.h"

# define MAP_TILE_SIZE 16
# define GAME_BORDER 50

typedef enum e_ErrorCode
{
	ENOCHAR = 100,
	ENOEXIT,
	ENOSTART,
	ENORECT,
	ENOWALLS,
	ENODOOR,
	ENOCOL,
	ENOEXIT2,
	ENOSTART2,
	ENOFORMAT,
	ENOLIST,
	ENOPATH,
	ENOINIT,
	ENOTILE,
	ENOWIN
}			t_ErrorCode;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_tile
{
	char	name[50];
	int		x;
	int		y;
	int		width;
	int		height;
	t_img	*img;
}				t_tile;

typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
	bool	on_exit;
}				t_player;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		p_count;
	int		c_count;
	int		e_count;
}			t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*tileset;
	t_img		*buffer;
	t_tile		**tiles;
	int			tilecount;
	t_map		*map;
	t_player	*player;
	t_player	*goblin;
	int			on_exit;
}				t_game;

extern t_game	*g_game;
extern t_map	*g_map;

/* Map Parser functions */
void	ft_parse_map(t_game *game, char *filename);
void	ft_read_map(char *filename, t_game *game);
int		ft_count_lines(char *filename);
void	ft_check_map(t_game *game);
void	ft_check_char(t_game *game, int x, int y);
void	ft_check_rectangle(t_game *game);
void	ft_check_door(t_game *game);
void	ft_check_wall(t_game *game);
void	ft_check_fill(t_game *game);
int		ft_count_collectibles(t_game *game);

/* Map Render functions */
void	ft_render_map(t_game *game);
void	ft_render_player(t_game *game);
void	ft_render_obj(t_game *game);
void	ft_render_game(t_game *game);
void	ft_clear_buffer(t_game *game, char *img_data, int bpp, int size_line);
void	ft_load_frame(t_game *game);
void	ft_put_tile(t_game *game, t_img *tile, int x, int y);
void	ft_put_tile_to_buffer(t_game *game, const char *tilename, int y, int x);
void	ft_put_tile_to_buffer_offset(t_game *game, const char *tilename,
			int y, int x, int offset_y, int offset_x);

/* Tileset Parser */
void	ft_load_tileset(t_game *game, const char *path);
void	ft_parse_tileset(t_game *game, char *filename);
t_tile	*ft_get_tile(t_game *game, const char *tile_name);
void	ft_blend_images(t_img *player, t_img *background);
void	ft_extract_frame(t_game *game, t_tile *tile);
void	ft_extract_split(char **parts, t_tile *tile);
void	ft_extract_by_pixels(t_img *frame, t_img *tileset, int x, int y);
bool	ft_check_tilelist(char *filename);

/* Events Functions */
void	ft_update_position(int keysym, int *y, int *x);
void	ft_update_goblin_position(t_game *game);
void	ft_check_exit(t_game *game, int new_y, int new_x);
void	ft_move_player(int keysym, t_game *game);
void	ft_update_player_move(t_game *game, const char *tilename, bool render);
void	ft_update_goblin_move(t_game *game, const char *tilename, bool render);
void	ft_render_player_anim(t_game *game);
void	ft_render_goblin_anim(t_game *game);
void	ft_render_info(t_game *game);
int		ft_player_anim(t_game *game);
void	ft_init_player_anim(t_game *game);

/* Garbage_collector function */
void	gc_destroy_tiles(t_game *game);
void	gc_destroy_tileset(t_game *game);

/* Utility functions */
int		ft_count_lines(char *filename);
void	ft_start_display(t_game *game, char *title);
void	ft_init_game(t_game *game, char *mapfile);
void	ft_exit_failure(t_game *game, int errnum);
void	ft_flood_fill(t_game *game, int x, int y);
int		ft_display_controls(int keysym, t_game *game);
int		ft_close_window(t_game *game);
int		ft_close_game(t_game *game);
void	ft_fill_image(char *img_data, int bpp, int size_line, int color);
void	ft_print_map(t_game *game);

/*	Test functions */
void	display_tiles(t_game *game);

#endif /*SO_LONG*/	
