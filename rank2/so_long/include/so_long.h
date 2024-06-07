/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:24:54 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/07 13:08:10 by jeportie         ###   ########.fr       */
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
# include <mlx.h>

# define MALLOC_ERR 1

# define WIDTH 1920
# define HEIGHT 1080
# define SCALE 20

# define TILE_SIZE_X 16
# define TILE_SIZE_Y 16

# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF
# define BLACK	0x000000
# define WHITE	0xFFFFFF

typedef struct s_gc_node
{
	void				*ptr;
	struct s_gc_node	*next;
}				t_gc_node;

typedef struct s_garbage_collector
{
	t_gc_node	*head;
}				t_gc;

extern t_gc	g_garbage_collector;

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

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	wall;
	t_img	floor;
	t_img	door;
	t_map	*map;
	int		win_width;
	int		win_height;
	int		zoom;
}				t_game;

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

/* Utility functions */
void	*gc_malloc(size_t size);
void	gc_register(void *ptr);
void	gc_cleanup(void);
void	mlx_start_display(t_game *data, char *title);
void	ft_exit_failure(t_game *data, int errnum);
void	ft_flood_fill(t_game *data, int x, int y);
void	ft_free_map(t_game *data);
int		ft_generate_color(int keysym, t_game *data);
int		ft_get_color(int keysym);
int		ft_display_controls(int keysym, t_game *data);
int		ft_close_window(t_game *data);
void	ft_fill_image(char *img_data, int bpp, int size_line, int color);

#endif /*SO_LONG*/	
