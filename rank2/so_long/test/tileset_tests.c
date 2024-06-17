/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tileset_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:15:26 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/17 18:31:44 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_tiles(t_game *data)
{
	int i;

	if (!data || !data->tiles)
		return;

	printf("Tileset contains %d tiles:\n", data->tilecount);
	for (i = 0; i < data->tilecount; i++)
	{
		printf("Tile %d:\n", i);
		printf("  Name: %s\n", data->tiles[i]->name);
		printf("  Position: (%d, %d)\n", data->tiles[i]->x, data->tiles[i]->y);
		printf("  Size: (%d x %d)\n", data->tiles[i]->width, data->tiles[i]->height);
	}
}
