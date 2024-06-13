/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tileset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:25:25 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/13 16:02:09 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_img	*load_tileset(t_game *game, const char *path)
{
	t_img	*tileset;

	tileset = gc_malloc(sizeof(t_img));
	if (!tileset)
		ft_exit_failure(game, ENOMEM);
	tileset->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			(char *)path, &tileset->width, &tileset->height);
	gc_mlx_image_register(tileset->img_ptr, game->mlx_ptr);
	if (!tileset->img_ptr)
		ft_exit_failure(game, ENOENT);
	tileset->img_data = mlx_get_data_addr(tileset->img_ptr,
			&tileset->bpp, &tileset->size_line, &tileset->endian);
	return (tileset);
}

//Reste a gerer erreur de parse exemple : mauvais format, mauvaise valeur, etc.
//Fonction ft_check_list a implementer et mettre juste apres gc_register(line).
t_img	ft_get_tile(t_game *data, t_img *tileset, const char *tile_name,
		const char *tile_list_path)
{
	int		fd;
	char	*line;
	char	**parts;
	t_tile	tile;

	fd = open(tile_list_path, O_RDONLY);
	gc_fd_register(fd);
	if (fd < 0)
		ft_exit_failure(data, ENOENT);
	line = get_next_line(fd);
	while (line)
	{
		gc_register(line);
		parts = ft_split(line, ' ');
		gc_nest_register(parts);
		if (!parts)
			ft_exit_failure(data, ENOMEM);
		if (!ft_strncmp(parts[0], tile_name, sizeof(parts[0])))
		{
			ft_extract_split(parts, &tile, tile_name);
			return (ft_extract_frame(data, tileset, &tile));
		}
	}
	ft_exit_failure(data, ENOTILE);
	return ((t_img){0});
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

t_img	ft_extract_frame(t_game *data, t_img *tileset, t_tile *tile)
{
	t_img	*frame;

	frame = gc_malloc(sizeof(t_img));
	if (!frame)
		ft_exit_failure(data, ENOMEM);
	frame->img_ptr = mlx_new_image(data->mlx_ptr, tile->width, tile->height);
	gc_mlx_image_register(tileset->img_ptr, data->mlx_ptr);
	frame->img_data = mlx_get_data_addr(frame->img_ptr, &frame->bpp,
			&frame->size_line, &frame->endian);
	frame->width = tile->width;
	frame->height = tile->height;
	ft_extract_by_pixels(frame, tileset, tile->x, tile->y);
	return (*frame);
}

void	ft_extract_split(char **parts, t_tile *tile, const char *tile_name)
{
	ft_strlcpy(tile->name, parts[0], sizeof(tile->name));
	tile->x = ft_atoi(parts[1]);
	tile->y = ft_atoi(parts[2]);
	tile->width = ft_atoi(parts[3]);
	tile->height = ft_atoi(parts[4]);
}
