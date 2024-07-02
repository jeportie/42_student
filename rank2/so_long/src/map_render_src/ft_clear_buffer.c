/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:16:13 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 15:12:23 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_clear_buffer(t_game *game, char *img_data, int bpp, int size_line)
{
	int				x;
	int				y;
	int				pixel_bytes;
	unsigned int	color;

	y = 0;
	color = 0x000000;
	pixel_bytes = bpp / 8;
	while (y < game->map->height * MAP_TILE_SIZE + 50)
	{
		x = 0;
		while (x < game->map->width * MAP_TILE_SIZE)
		{
			*(unsigned int *)(img_data + (y * size_line)
					+ (x * pixel_bytes)) = color;
			x++;
		}
		y++;
	}
}
