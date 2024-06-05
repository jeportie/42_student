/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 23:43:43 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/05 23:45:46 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "include/ft_printf.h"

int	ft_display_controls(int keysym, t_game *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	return (0);
}

int	ft_get_color(int keysym)
{
	if (keysym == XK_r)
		return (RED);
	else if (keysym == XK_g)
		return (GREEN);
	else if (keysym == XK_b)
		return (BLUE);
	else
		return (BLACK);
}

void	ft_fill_image(char *img_data, int bpp, int size_line, int color)
{
	int	pixel;
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel = (y * size_line) + (x * (bpp / 8));
			img_data[pixel] = color & 0xFF;
			img_data[pixel + 1] = (color >> 8) & 0xFF;
			img_data[pixel + 2] = (color >> 16) & 0xFF;
			x++;
		}
		y++;
	}
}

int	ft_generate_color(int keysym, t_game *data)
{
	int			color;
	t_img		img;

	ft_printf("The %d key has been pressed\n\n", keysym);
	color = ft_get_color(keysym);
	ft_display_controls(keysym, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	img.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	img.img_data = mlx_get_data_addr(img.img_ptr, &img.bpp,
			&img.size_line, &img.endian);
	ft_fill_image(img.img_data, img.bpp, img.size_line, color);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, img.img_ptr);
	return (1);
}
