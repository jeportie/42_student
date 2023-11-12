/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fclose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:38:42 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/12 20:42:56 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filemanip.h"

void	ft_fclose(int fd)
{
	if (fd < 0)
	{
		perror("Invalid file descriptor.\n");
		exit(EXIT_FAILURE);
	}
	if (close(fd) == -1)
	{
		perror("Error: closing file failed.");
		exit(EXIT_FAILURE);	
	}
	return ;
}
