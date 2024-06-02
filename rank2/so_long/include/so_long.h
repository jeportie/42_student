/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:24:54 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/03 00:48:26 by jeportie         ###   ########.fr       */
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

typedef struct s_mix_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx_data;

typedef struct s_img_data
{
	void	*img_ptr;
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img_data;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectible_count;
	int		exit_count;
}			t_map;

/* Utility functions */

#endif /*SO_LONG*/	
