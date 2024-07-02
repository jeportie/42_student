/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_anim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:26:29 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 14:49:53 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_player_anim(t_game *game)
{
	static long	count;

	count = 2000;
	if (game->player->x == game->goblin->x
		&& game->player->y == game->goblin->y)
		ft_close_game(game);
	count--;
	if (!count)
	{
		ft_render_player_anim(game);
		ft_render_goblin_anim(game);
		count = 2000;
	}
	return (0);
}
