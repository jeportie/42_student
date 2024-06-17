/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_controls.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:44:18 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/17 16:50:08 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include <X11/keysym.h>
#include <X11/X.h>

int	ft_display_controls(int keysym, t_game *data)
{
	if (keysym == XK_Escape)
	{
		gc_destroy_tiles(data);
		gc_destroy_tileset(data);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		gc_cleanup();
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	ft_close_window(t_game *data)
{
	gc_destroy_tiles(data);
	gc_destroy_tileset(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	gc_cleanup();
	exit(EXIT_SUCCESS);
	return (0);
}
