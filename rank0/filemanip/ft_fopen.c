/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:17:37 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/28 03:49:10 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

int	ft_fopen(const char *file_path, int option)
{
	int	fd;

	fd = open(file_path, option);
	if (fd == -1)
	{
		perror("Error opening test file:");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
