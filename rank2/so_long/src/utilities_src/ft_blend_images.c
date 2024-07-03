/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blend_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:14:22 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/03 11:48:24 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_blend_images(t_img *src, t_img *dest)
{
	int	fg_color;
	int	*bg_pixel;
	int	*fg_pixel;
	int	x;
	int	y;

	y = 0;
	while (y < src->height)
	{
		x = 0;
		while (x < src->width)
		{
			bg_pixel = (int *)(dest->img_data + (y * dest->size_line
						+ x * (dest->bpp / 8)));
			fg_pixel = (int *)(src->img_data + (y * src->size_line
						+ x * (src->bpp / 8)));
			fg_color = *fg_pixel;
			if ((fg_color & 0xFF000000) != 0xFF000000)
				*bg_pixel = *fg_pixel;
			x++;
		}
		y++;
	}
}
