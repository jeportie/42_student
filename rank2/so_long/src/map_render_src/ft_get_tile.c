/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:23:18 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 14:23:18 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_tile	*ft_get_tile(t_game *game, const char *filename)
{
	int	i;

	i = 0;
	while (i < game->tilecount)
	{
		if (!ft_strncmp(game->tiles[i]->name, filename,
				ft_strlen(filename)))
			return (game->tiles[i]);
		i++;
	}
	return (NULL);
}
