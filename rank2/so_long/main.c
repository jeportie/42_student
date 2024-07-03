/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:57:08 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/03 10:30:43 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

t_game		*g_game = NULL;
t_map		*g_map = NULL;

int	main(int argc, char **argv)
{
	t_game	game = {0};

	if (argc != 2)
		ft_exit_failure(&game, ENOFORMAT);
	ft_init_game(&game, argv[1]);
	ft_render_game(&game);
	mlx_hook(game.win_ptr, 17, 0, ft_close_game, &game);
	mlx_key_hook(game.win_ptr, ft_display_controls, &game);
	mlx_loop_hook(game.mlx_ptr, ft_player_anim, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
