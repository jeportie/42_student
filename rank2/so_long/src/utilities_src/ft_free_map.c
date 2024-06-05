/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 00:05:25 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/06 00:05:25 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_free_map(t_game *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (i < data->map->height)
		{
			free(data->map->map[i]);
			i++;
		}
		free(data->map);
	}
	free(data);
}
