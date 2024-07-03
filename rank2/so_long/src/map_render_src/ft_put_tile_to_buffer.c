/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tile_to_buffer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:57:54 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/03 10:28:12 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_put_tile_to_buffer(t_game *game, const char *tilename, int y, int x)
{	
	t_tile	*tile;
	int		i;
	int		j;

	tile = ft_get_tile(game, tilename);
	if (!tile || !tile->img)
		ft_exit_failure(game, ENOTILE);
	if (ft_strncmp(tilename, "coin", ft_strlen(tilename)))
		tile->offset = 5;
	i = 0;
	while (i < tile->width)
	{
		j = 0;
		while (j < tile->height)
		{
			*(unsigned int *)(game->buffer->img_data + ((y * 16 + j
							+ tile->offset) * game->buffer->size_line)
					+ ((x * 16 + i + tile->offset) * (tile->img->bpp / 8)))
				= *(unsigned int *)(tile->img->img_data
					+ (j * tile->img->size_line) + (i * (tile->img->bpp / 8)));
			j++;
		}
		i++;
	}
}
