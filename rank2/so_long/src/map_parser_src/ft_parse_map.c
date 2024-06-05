/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:06:07 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/06 00:24:08 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_parse_map(t_game *data, char *filename)
{
	data->map = (t_map *)malloc(sizeof(t_map));
	if (!data)
	{
		errno = ENOMEM;
		ft_exit_failure(NULL, ENOMEM);
	}
	ft_read_map(filename, data);
	ft_check_map(data);
}
/* Need to free t_map *data when the game end or when we change the map.*/
