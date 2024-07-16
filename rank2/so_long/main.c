/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:57:08 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/16 19:56:35 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	game.state = NO_WIN;
	if (argc != 2)
		ft_exit_failure(&game, ENOFORMAT);
	ft_init_game(&game, argv[1]);
	gc_collect();
	ft_render_game(&game);
	gc_collect();
	mlx_hook(game.win_ptr, 17, 0, ft_close_game, &game);
	mlx_key_hook(game.win_ptr, ft_display_controls, &game);
	mlx_loop_hook(game.mlx_ptr, ft_player_anim, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
