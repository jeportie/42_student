/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tile_to_buffer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:57:54 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 15:21:28 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_put_tile_to_buffer(t_game *game, const char *tilename, int y, int x)
{	
	t_tile	*tile;
	char	*src_data;
	char	*dest_data;
	int		src_line_size;
	int		dest_line_size;
	int		bpp;
	int		i;
	int		j;

	tile = ft_get_tile(game, tilename);
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
					+ ((x * 16 + i) * bpp))
				= *(unsigned int *)(src_data + (j * src_line_size) + (i * bpp));
			j++;
		}
		i++;
	}
}

void	ft_put_tile_to_buffer_offset(t_game *game, const char *tilename,
		int y, int x, int offset_y, int offset_x)
{
	t_tile	*tile;
	char	*src_data;
	char	*dest_data;
	int		src_line_size;
	int		dest_line_size;
	int		bpp;
	int		i;
	int		j;

	tile = ft_get_tile(game, tilename);
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
			*(unsigned int *)(dest_data + ((y * 16 + i + offset_y)
						* dest_line_size) + ((x * 16 + j + offset_x) * bpp))
				= *(unsigned int *)(src_data + (i * src_line_size)
					+ (j * bpp));
			j++;
		}
		i++;
	}
}
