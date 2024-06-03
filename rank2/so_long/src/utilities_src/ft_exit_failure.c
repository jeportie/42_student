/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_failure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:08:42 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/03 19:08:58 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_exit_failure(t_map *data, int errnum)
{
	const char	*error_messages[] = {
		"Invalid character present in map.\n",
		"Multiple exits not allowed.\n",
		"Multiple starting positions not allowed.\n",
		"Map is not rectangular.\n",
		"Map is not fully enclosed by walls.\n",
		"No collectibles found in the map.\n",
		"No exit found in the map.\n",
		"No start position in the map.\n"
	};

	errno = errnum;
	if (errnum >= ENOCHAR && errnum <= ENOSTART2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd((char *)error_messages[errnum - 100], 2);
	}
	else if (errnum == ENOMEM || errnum == ENOENT)
		perror("Error");
	else
		ft_putstr_fd("Unknown error\n", 2);
	if (data)
		ft_free_map(data);
	exit(EXIT_FAILURE);
}
