/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tileset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:25:25 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/18 16:59:09 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_parse_tileset(t_game *data, char *filename)
{
	int		fd;
	t_tile	**tiles;
	t_tile	*tile;
	char	**parts;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	gc_fd_register(fd);
	if (fd < 0)
		ft_exit_failure(data, ENOENT);
	data->tilecount = ft_count_lines(filename);
	tiles = gc_malloc(sizeof(t_tile) * (data->tilecount + 1));
	if (!tiles)
		ft_exit_failure(data, ENOMEM);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		gc_register(line);
		tile = gc_malloc(sizeof(t_tile));
		if (!tile)
			ft_exit_failure(data, ENOMEM);
		parts = ft_split(line, ' ');
		gc_nest_register(parts);
		if (!parts)
			ft_exit_failure(data, ENOMEM);
		ft_extract_split(parts, tile, filename);
		ft_extract_frame(data, tile, i);
		tiles[i++] = tile;
		line = get_next_line(fd);
	}
	tiles[i] = NULL;
	close (fd);
    data->tiles = tiles;
}

void	ft_extract_by_pixels(t_img *frame, t_img *tileset, int x, int y)
{
	int		color;
	int		i;
	int		j;

	j = 0;
	while (j < frame->height)
	{
		i = 0;
		while (i < frame->width)
		{
			color = *(int *)(tileset->img_data + ((y + j)
						* tileset->size_line + (x + i) * (tileset->bpp / 8)));
			*(int *)(frame->img_data + (j * frame->size_line
						+ i * (frame->bpp / 8))) = color;
			i++;
		}
		j++;
	}
}

void	ft_extract_frame(t_game *data, t_tile *tile, int index)
{
	t_img	*frame;

	frame = gc_malloc(sizeof(t_img));
	if (!frame)
		ft_exit_failure(data, ENOMEM);
	frame->img_ptr = mlx_new_image(data->mlx_ptr, tile->width, tile->height);
	if (!frame->img_ptr)
		ft_exit_failure(data, ENOMEM);
	frame->img_data = mlx_get_data_addr(frame->img_ptr, &frame->bpp, &frame->size_line, &frame->endian);
	frame->width = tile->width;
	frame->height = tile->height;
	ft_extract_by_pixels(frame, data->tileset, tile->x, tile->y);
	tile->img = *frame;
}

void	ft_extract_split(char **parts, t_tile *tile, const char *tile_name)
{
	ft_strlcpy(tile->name, parts[0], sizeof(tile->name));
	tile->x = ft_atoi(parts[1]);
	tile->y = ft_atoi(parts[2]);
	tile->width = ft_atoi(parts[3]);
	tile->height = ft_atoi(parts[4]);
}
