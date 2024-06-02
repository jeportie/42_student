/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:57:08 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/02 21:42:03 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include "include/ft_printf.h"

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

void	ft_display_controls(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
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

int	ft_generate_color(int keysym, t_mlx_data *data)
{
	int			color;
	t_img_data	img_data;

	ft_printf("The %d key has been pressed\n\n", keysym);
	color = ft_get_color(keysym);
	ft_display_controls(keysym, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	img_data.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	img_data.img_data = mlx_get_data_addr(img_data.img_ptr,
			&img_data.bpp, &img_data.size_line, &img_data.endian);
	ft_fill_image(img_data.img_data, img_data.bpp,
		img_data.size_line, color);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		img_data.img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, img_data.img_ptr);
	return (1);
}

void	mlx_start_display(t_mlx_data *data, int width, int height, char *title)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		perror("Failed to initialize mlx.\n");
		exit (EXIT_FAILURE);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "Hello Jeje!");
	if (!data->win_ptr)
	{
		perror("Failed to create window");
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit (EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;

	mlx_start_display(&data, 1200, 800, "TEST");
	mlx_key_hook(data.win_ptr, ft_generate_color, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
