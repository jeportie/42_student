/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:24:54 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/11 20:33:53 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>
# include <X11/keysym.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "printf.h"
# include "mlx.h"

# define WIDTH	1920
# define HEIGHT 1080
# define SCALE 20

# define TILE_SIZE_X 16
# define TILE_SIZE_Y 16

# define DESTROY_IMAGE 0
# define DESTROY_WINDOW 1
# define DESTROY_DISPLAY 2

typedef enum e_ErrorCode
{
	ENOCHAR = 100,
	ENOEXIT,
	ENOSTART,
	ENORECT,
	ENOWALLS,
	ENOCOL,
	ENOEXIT2,
	ENOSTART2,
	ENOFORMAT,
	ENOPATH,
	ENOINIT,
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

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		player_count;
	int		collectible_count;
	int		exit_count;
}			t_map;

typedef struct s_tile
{
	char	name[50];
	int		x;
	int		y;
	int		width;
	int		height;
	t_img	img;
}				t_tile;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	wall;
	t_img	floor;
	t_img	door;
	t_img	tileset;
	t_tile	**tiles;
	int		tilecount;
	t_map	*map;
}				t_game;

extern t_game	*g_game;
extern t_map	*g_map;

typedef struct s_gc_node
{
	void				*ptr;
	int					marked;
	int					is_array;
	int					mlx_option;
	t_game				*game;
	struct s_gc_node	*next;
}				t_gc_node;

typedef struct s_garbage_collector
{
	t_gc_node	*head;
}				t_gc;

extern t_gc	g_garbage_collector;

/* Map Parser functions */
void	ft_parse_map(t_game *data, char *filename);
void	ft_read_map(char *filename, t_game *data);
int		ft_count_lines(char *filename);
void	ft_allocate_map(t_game *data);
void	ft_store_map(char *filename, t_game *data);
void	ft_check_map(t_game *data);
void	ft_check_char(t_game *data, int x, int y);
void	ft_check_rectangle(t_game *data);
void	ft_check_fill(t_game *data);

/* Map Render functions */
void	ft_render_map(t_game *game);
void	ft_load_frame(t_game *game);
void	ft_put_tile(t_game *game, t_img *tile, int x, int y);

/* Tileset Parser */
t_tile	**ft_parse_tileset(t_game *data, char *filename,
			t_img *tileset, int *tilecount);
t_img	ft_extract_frame(t_game *data, t_img *tileset, t_tile *tile);

/* Garbage_collector function */
void	*gc_malloc(size_t size);
void	gc_register(void *ptr);
void	gc_nest_register(void *ptr);
void	gc_mlx_register(void *ptr, int mlx_destroy_code, t_game *data);
void	gc_cleanup(void);

void	gc_collect();
void	gc_mark(void *ptr);	
void	gc_mark_from_roots(void);
void	gc_sweep(void);

/* Utility functions */
void	ft_start_display(t_game *data, char *title);
void	ft_exit_failure(t_game *data, int errnum);
void	ft_flood_fill(t_game *data, int x, int y);
int		ft_display_controls(int keysym, t_game *data);
int		ft_close_window(t_game *data);
void	ft_fill_image(char *img_data, int bpp, int size_line, int color);

#endif /*SO_LONG*/	
