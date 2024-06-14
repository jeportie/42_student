/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:24:54 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/14 16:28:01 by jeportie         ###   ########.fr       */
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

# define FALSE 0
# define TRUE 1

# define WIDTH 2000	
# define HEIGHT 2000
# define SCALE 20

# define TILE_SIZE_X 16
# define TILE_SIZE_Y 16

# define DESTROY_IMAGE 1
# define DESTROY_WINDOW 2

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
	t_img	*tileset;
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
	void				*mlx_ptr;
	t_game				*data;
	int					fd;
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
void	ft_load_tileset(t_game *game, const char *path);
t_tile	**ft_parse_tileset(t_game *data, char *filename, int *tilecount);

void	ft_get_tile(t_game *data, const char *tile_name, const char *tile_list_path);
void	ft_extract_frame(t_game *data, t_tile *tile);
void	ft_extract_split(char **parts, t_tile *tile, const char *tile_name);
void	ft_extract_by_pixels(t_img *frame, t_img *tileset, int x, int y);

/* Garbage_collector function */
void	*gc_malloc(size_t size);
void	gc_register(void *ptr);
void	gc_nest_register(void *ptr);
void	gc_mlx_image_register(void *img_ptr, void *mlx_ptr);
void	gc_fd_register(int fd);
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
