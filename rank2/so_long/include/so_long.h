/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:24:54 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/21 18:31:07 by jeportie         ###   ########.fr       */
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
# include <stdbool.h>
# include <stdio.h>
# include "libft.h"
# include "printf.h"
# include "mlx.h"

# define WIDTH 866	
# define HEIGHT 600
# define SCALE 20

# define MAP_TILE_SIZE 16


typedef struct s_gc_node
{
	void				*ptr;
	bool				is_marked;
	bool				is_array;
	int					fd;
	struct s_gc_node	*next;
}				t_gc_node;

typedef struct s_garbage_collector
{
	t_gc_node	*head;
}				t_gc;

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
	t_tile		**tiles;
	int			tilecount;
	t_map		*map;
	t_player	*player;
	int			on_exit;
}				t_game;

extern t_gc		g_garbage_collector;
extern t_game	*g_game;
extern t_map	*g_map;

/* Map Parser functions */
void	ft_parse_map(t_game *game, char *filename);
void	ft_read_map(char *filename, t_game *game);
int		ft_count_lines(char *filename);
void	ft_allocate_map(t_game *game);
void	ft_store_map(char *filename, t_game *game);
void	ft_check_map(t_game *game);
void	ft_check_char(t_game *game, int x, int y);
void	ft_check_rectangle(t_game *game);
void	ft_check_fill(t_game *game);
int		ft_count_collectibles(t_game *game);

/* Map Render functions */
void	ft_render_map(t_game *game);
void	ft_render_obj(t_game *game);
void	ft_render_game(t_game *game);
void	ft_load_frame(t_game *game);
void	ft_put_tile(t_game *game, t_img *tile, int x, int y);

/* Tileset Parser */
void	ft_load_tileset(t_game *game, const char *path);
void	ft_parse_tileset(t_game *game, char *filename);
t_tile	*ft_get_tile(t_game *game, const char *tile_name);
void	ft_blend_images(t_img *player, t_img *background);
void	ft_extract_frame(t_game *game, t_tile *tile, int i);
void	ft_extract_split(char **parts, t_tile *tile, const char *tile_name);
void	ft_extract_by_pixels(t_img *frame, t_img *tileset, int x, int y);

/* Garbage_collector function */
void	*gc_malloc(size_t size);
void	gc_register(void *ptr);
void	gc_nest_register(void *ptr);
void	gc_fd_register(int fd);
void	gc_cleanup(void);
void	gc_destroy_tiles(t_game *game);
void	gc_destroy_tileset(t_game *game);
void	gc_collect(void);
void	gc_mark(void *ptr);	
void	gc_mark_from_roots(void);
void	gc_sweep(void);

/* Utility functions */
void	ft_start_display(t_game *game, char *title);
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
