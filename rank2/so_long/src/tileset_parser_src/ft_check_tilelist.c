/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tilelist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:04:16 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 11:05:15 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

bool	ft_check_tilelist(char *filename)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(filename, O_RDONLY);
	gc_fd_register(fd);
	if (fd < 0)
	{
		errno = ENOENT;
		ft_exit_failure(NULL, ENOENT);
	}
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
