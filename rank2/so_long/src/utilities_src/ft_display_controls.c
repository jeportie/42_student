/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_controls.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:44:18 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/10 12:55:28 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include <X11/keysym.h>
#include <X11/X.h>

int	ft_display_controls(int keysym, t_game *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(data->mlx_ptr, data->door.img_ptr);
		mlx_destroy_image(data->mlx_ptr, data->floor.img_ptr);
		mlx_destroy_image(data->mlx_ptr, data->wall.img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		gc_cleanup();
		exit(0);
	}
	return (0);
}

int	ft_close_window(t_game *data)
{
	mlx_destroy_image(data->mlx_ptr, data->door.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->floor.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->wall.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	gc_cleanup();
	exit(0);
	return (0);
}
