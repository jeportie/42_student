/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chek_rectangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:45:50 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 12:45:50 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_check_rectangle(t_game *game)
{
	int	width;
	int	i;

	width = ft_strlen(game->map->map[0]);
	i = 0;
	while (i < game->map->height)
	{
		if ((int)ft_strlen(game->map->map[i]) != width)
			ft_exit_failure(game, ENORECT);
		i++;
	}
	game->map->width = width - 1;
}
