/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_frame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:33:14 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/07 15:15:08 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_load_frame(t_game *game)
{
	game->wall.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"/home/jeromep/Documents/42_student/rank2/so_long/assets/frames/wall.xpm",
			&game->wall.width, &game->wall.height);
	gc_register(game->wall.img_ptr);
	if (!game->wall.img_ptr)
		ft_exit_failure(game, ENOENT);
	game->wall.img_data = mlx_get_data_addr(game->wall.img_ptr,
			&game->wall.bpp, &game->wall.size_line, &game->wall.endian);

	game->floor.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"/home/jeromep/Documents/42_student/rank2/so_long/assets/frames/floor.xpm",
			&game->floor.width, &game->floor.height);
	gc_register(game->floor.img_ptr);
	if (!game->floor.img_ptr)
		ft_exit_failure(game, ENOENT);
	game->floor.img_data = mlx_get_data_addr(game->floor.img_ptr,
			&game->floor.bpp, &game->floor.size_line, &game->floor.endian);

	game->door.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"/home/jeromep/Documents/42_student/rank2/so_long/assets/frames/door.xpm",
			&game->door.width, &game->door.height);
	gc_register(game->door.img_ptr);
	if (!game->door.img_ptr)
		ft_exit_failure(game, ENOENT);
	game->door.img_data = mlx_get_data_addr(game->door.img_ptr,
			&game->door.bpp, &game->door.size_line, &game->door.endian);
}
