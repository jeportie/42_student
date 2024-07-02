/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:22:17 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 15:24:21 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_render_game(t_game *game)
{
	ft_render_info(game);
	ft_render_map(game);
	ft_render_obj(game);
	ft_render_player(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->buffer->img_ptr, 0, 0);
}
