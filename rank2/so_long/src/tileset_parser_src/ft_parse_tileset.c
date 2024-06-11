/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tileset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:25:25 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/11 20:51:17 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

bool is_tile_required(const char *tile_name, const char *required_tiles[], int required_tile_count)
{
	int	i;

	i = 0;
    while (i < required_tile_count)
    {
        if (strcmp(tile_name, required_tiles[i]) == 0)
            return true;
		i++;
    }
    return false;
}

t_img *load_tileset(t_game *game, const char *path)
{
    t_img *tileset = gc_malloc(sizeof(t_img));
    if (!tileset)
        ft_exit_failure(game, ENOMEM);

    tileset->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, (char *)path, &tileset->width, &tileset->height);
    if (!tileset->img_ptr)
        ft_exit_failure(game, ENOENT);

    tileset->img_data = mlx_get_data_addr(tileset->img_ptr, &tileset->bpp, &tileset->size_line, &tileset->endian);
    return tileset;
}

t_img	ft_extract_frame(t_game *data, t_img *tileset, t_tile *tile)
{
    t_img *frame = gc_malloc(sizeof(t_img));
    if (!frame)
        ft_exit_failure(data, ENOMEM);

    frame->img_ptr = mlx_new_image(data->mlx_ptr, tile->width, tile->height);
    frame->img_data = mlx_get_data_addr(frame->img_ptr, &frame->bpp, &frame->size_line, &frame->endian);

    for (int j = 0; j < tile->height; j++)
    {
        for (int i = 0; i < tile->width; i++)
        {
            int color = *(int *)(tileset->img_data + ((tile->y + j) * tileset->size_line + (tile->x + i) * (tileset->bpp / 8)));
            *(int *)(frame->img_data + (j * frame->size_line + i * (frame->bpp / 8))) = color;
        }
    }
    frame->width = tile->width;
    frame->height = tile->height;
    return *frame;
}

t_tile	**ft_parse_tileset(t_game *data, char *filename, t_img *tileset,
		int *tilecount)
{
	int		fd;
	t_tile	**tiles;
	t_tile	*tile;
	char	**parts;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_exit_failure(data, ENOENT);
	*tilecount = ft_count_lines(filename);
	tiles = gc_malloc(sizeof(t_tile) * (*tilecount + 1));
	if (!tiles)
	{
		close(fd);
		ft_exit_failure(data, ENOMEM);
	}
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		gc_register(line);
		tile = gc_malloc(sizeof(t_tile));
		if (!tile)
		{
			close(fd);
			ft_exit_failure(data, ENOMEM);
		}
		parts = ft_split(line, ' ');
		if (!parts)
		{
			close(fd);
			ft_exit_failure(data, ENOMEM);
		}
		gc_nest_register(parts);
		ft_strlcpy(tile->name, parts[0], sizeof(tile->name));
		tile->x = ft_atoi(parts[1]);
		tile->y = ft_atoi(parts[2]);
		tile->width = ft_atoi(parts[3]);
		tile->height = ft_atoi(parts[4]);
		tile->img = ft_extract_frame(data, tileset, tile);
		tiles[i++] = tile;
		line = get_next_line(fd);
	}
	tiles[i] = NULL;
	close (fd);
	return (tiles);
}
