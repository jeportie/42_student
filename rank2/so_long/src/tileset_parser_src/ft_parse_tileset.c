/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tileset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:25:25 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/14 16:20:54 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"


void	ft_load_tileset(t_game *game, const char *path)
{
	game->tileset = gc_malloc(sizeof(t_img));
	if (!game->tileset)
		ft_exit_failure(game, ENOMEM);
	game->tileset->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			(char *)path, &game->tileset->width, &game->tileset->height);
	gc_mlx_image_register(game->tileset->img_ptr, game->mlx_ptr);
	if (!game->tileset->img_ptr)
	{
		printf("Tileset not found\n");
		ft_exit_failure(game, ENOENT);
	}
	game->tileset->img_data = mlx_get_data_addr(game->tileset->img_ptr,
			&game->tileset->bpp, &game->tileset->size_line, &game->tileset->endian);
}

t_tile	**ft_parse_tileset(t_game *data, char *filename, int *tilecount)
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
	*tilecount = ft_count_lines(filename);
	tiles = gc_malloc(sizeof(t_tile) * (*tilecount + 1));
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
		if (!parts)
			ft_exit_failure(data, ENOMEM);
		gc_nest_register(parts);
		ft_extract_split(parts, tile, filename);
		ft_extract_frame(data, tile);
		tiles[i++] = tile;
		line = get_next_line(fd);
	}
	tiles[i] = NULL;
	close (fd);
	return (tiles);
}

//Reste a gerer erreur de parse exemple : mauvais format, mauvaise valeur, etc.
//Fonction ft_check_list a implementer et mettre juste apres gc_register(line).
void	ft_get_tile(t_game *data, const char *tile_name, const char *tile_list_path)
{
	int		fd;
	char	*line;
	char	**parts;
	t_tile	tile;

	fd = open(tile_list_path, O_RDONLY);
	gc_fd_register(fd);
	if (fd < 0)
	{
		printf("Tile list not found\n");
		ft_exit_failure(data, ENOENT);
	}
	line = get_next_line(fd);
	gc_register(line);
	while (line)
	{
		parts = ft_split(line, ' ');
		if (!parts)
			ft_exit_failure(data, ENOMEM);
		gc_nest_register(parts);
		if (!ft_strncmp(parts[0], tile_name, sizeof(parts[0])))
		{
			ft_extract_split(parts, &tile, tile_name);
			ft_extract_frame(data, &tile);
			return ;
		}
	}
	ft_exit_failure(data, ENOTILE);
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

void	ft_extract_frame(t_game *data, t_tile *tile)
{
	t_img	*frame;

	frame = gc_malloc(sizeof(t_img));
	if (!frame)
		ft_exit_failure(data, ENOMEM);
	frame->img_ptr = mlx_new_image(data->mlx_ptr, tile->width, tile->height);
	gc_mlx_image_register(data->tileset->img_ptr, data->mlx_ptr);
	frame->img_data = mlx_get_data_addr(frame->img_ptr, &frame->bpp,
			&frame->size_line, &frame->endian);
	frame->width = tile->width;
	frame->height = tile->height;
	ft_extract_by_pixels(frame, data->tileset, tile->x, tile->y);
}

void	ft_extract_split(char **parts, t_tile *tile, const char *tile_name)
{
	ft_strlcpy(tile->name, parts[0], sizeof(tile->name));
	tile->x = ft_atoi(parts[1]);
	tile->y = ft_atoi(parts[2]);
	tile->width = ft_atoi(parts[3]);
	tile->height = ft_atoi(parts[4]);
}
