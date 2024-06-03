/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:24:54 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/03 19:04:28 by jeportie         ###   ########.fr       */
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

# define MALLOC_ERR 1

# define WIDTH 1200
# define HEIGHT 800

# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF
# define BLACK	0x000000
# define WHITE	0xFFFFFF

typedef enum e_ErrorCode
{
	ENOCHAR = 100,
	ENOEXIT,
	ENOSTART,
	ENORECT,
	ENOWALLS,
	ENOCOL,
	ENOEXIT2,
	ENOSTART2
}			t_ErrorCode;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
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

/* Map Parser functions */
t_map	*ft_parse_map(char *filename);

void	ft_read_map(char *filename, t_map *data);
int		ft_count_lines(char *filename);
void	ft_allocate_map(t_map *data);
void	ft_store_map(char *filename, t_map *data);

void	ft_check_map(t_map *data);
void	ft_check_char(t_map *data, int x, int y);
void	ft_check_rectangle(t_map *data);
void	ft_check_fill(t_map *data);

/* Utility functions */
void	ft_exit_failure(t_map *data, int errnum);
void	ft_flood_fill(t_map *data, int x, int y);
void	ft_free_map(t_map *data);

#endif /*SO_LONG*/	
