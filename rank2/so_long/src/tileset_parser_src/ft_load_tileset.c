/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_tileset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:14:11 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/17 17:14:14 by jeportie         ###   ########.fr       */
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
	if (!game->tileset->img_ptr)
	{
		printf("Tileset not found\n");
		ft_exit_failure(game, ENOENT);
	}
	game->tileset->img_data = mlx_get_data_addr(game->tileset->img_ptr,
			&game->tileset->bpp, &game->tileset->size_line, &game->tileset->endian);
}
