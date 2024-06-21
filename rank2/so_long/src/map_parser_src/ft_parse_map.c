/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:06:07 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/21 13:25:07 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_parse_map(t_game *game, char *filename)
{
	game->map = gc_malloc(sizeof(t_map));
	if (!game->map)
	{
		errno = ENOMEM;
		ft_exit_failure(NULL, ENOMEM);
	}
	ft_read_map(filename, game);
	ft_check_map(game);
}
/* Need to free t_map *game when the game end or when we change the map.*/
