/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player_anim.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:53:47 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 14:53:47 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_init_player_anim(t_game *game)
{
	ft_blend_images(ft_get_tile(game, "knight_f_idle_anim_f0")->img,
		ft_get_tile(game, "1b")->img);
	ft_blend_images(ft_get_tile(game, "knight_f_idle_anim_f1")->img,
		ft_get_tile(game, "2b")->img);
	ft_blend_images(ft_get_tile(game, "knight_f_idle_anim_f2")->img,
		ft_get_tile(game, "3b")->img);
	ft_blend_images(ft_get_tile(game, "knight_f_idle_anim_f3")->img,
		ft_get_tile(game, "4b")->img);
	ft_blend_images(ft_get_tile(game, "masked_orc_idle_anim_f0")->img,
		ft_get_tile(game, "1m")->img);
	ft_blend_images(ft_get_tile(game, "masked_orc_idle_anim_f1")->img,
		ft_get_tile(game, "2m")->img);
	ft_blend_images(ft_get_tile(game, "masked_orc_idle_anim_f2")->img,
		ft_get_tile(game, "3m")->img);
	ft_blend_images(ft_get_tile(game, "masked_orc_idle_anim_f3")->img,
		ft_get_tile(game, "4m")->img);
}
