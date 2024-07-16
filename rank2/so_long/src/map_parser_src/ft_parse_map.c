/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:06:07 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 12:53:10 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_parse_map(t_game *game, char *filename)
{
	game->map = gc_malloc(sizeof(t_map));
	check_malloc(game->map);
	gc_lock(game->map);
	ft_read_map(filename, game);
	ft_check_map(game);
}
