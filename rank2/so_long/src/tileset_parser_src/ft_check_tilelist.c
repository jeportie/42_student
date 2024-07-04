/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tilelist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:04:16 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/04 18:03:43 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

bool	ft_check_tilelist(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		errno = ENOENT;
		ft_putstr_fd("Tile list not found\n", 2);
		ft_exit_failure(game, ENOENT);
	}
	gc_fd_register(fd);
	line = get_next_line(fd);
	while (line)
	{
		if (*line == '\n')
			count++;
		free(line);
		line = get_next_line(fd);
	}
	if (count)
		return (false);
	return (true);
}
