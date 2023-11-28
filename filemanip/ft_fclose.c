/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fclose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:38:42 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/28 03:48:16 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

int	ft_fclose(int fd)
{
	if (fd < 0)
	{
		perror("Invalid file descriptor:");
		return (0);
	}
	if (close(fd) == -1)
	{
		perror("Error closing test file:");
		return (0);	
	}
	return (1);
}
