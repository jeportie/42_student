/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_failure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:08:42 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/16 19:54:06 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

const char	*g_error_messages[] = {
	"Invalid character present in map.\n",
	"Multiple exits not allowed.\n",
	"Multiple starting positions not allowed.\n",
	"Map is not rectangular.\n",
	"Map is not fully enclosed by walls.\n",
	"Door need to have more floor space.\n",
	"No collectibles found in the map.\n",
	"No exit found in the map.\n",
	"No start position in the map.\n",
	"Usage : ./so_long <map_file.ber>\n",
	"Tileset list has an invalid format.\n",
	"Map has no possible path to exit.\n",
	"Failed to initialize mlx.\n",
	"Failed to find tile in tileset.\n",
	"Failed to create window.\n"
};

static void	ft_exit_tiles(t_game *game)
{
	if (game->tiles)
	{
		gc_destroy_tiles(game);
		gc_destroy_tileset(game);
	}
}

static void	ft_exit_device(t_game *game)
{
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
}

void	ft_exit_failure(t_game *game, int errnum)
{
	errno = errnum;
	if (errnum >= ENOCHAR && errnum <= ENOPATH)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd((char *)g_error_messages[errnum - 100], 2);
	}
	else if (errnum == ENOMEM || errnum == ENOENT)
		perror("Error");
	else if (errnum >= ENOINIT && errnum <= ENOWIN)
		perror((char *)g_error_messages[errnum - 100]);
	else
		ft_putstr_fd("Unknown error\n", 2);
	if (game != NULL && game->state == LOADED)
		ft_exit_tiles(game);
	if (game != NULL && (game->state == LOADED || game->state == NO_TILE))
		ft_exit_device(game);
	gc_cleanup();
	exit(EXIT_FAILURE);
}
