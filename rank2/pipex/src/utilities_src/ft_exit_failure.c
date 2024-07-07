/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_failure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:08:42 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/27 18:23:06 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	ft_check_fd(int fd, const char *error_message)
{
	if (fd == -1)
	{
		perror(error_message);
		gc_cleanup();
		exit(EXIT_FAILURE);
	}
}

void	ft_check_malloc(void *ptr, const char *error_message)
{
	if (!ptr)
	{
		perror(error_message);
		gc_cleanup();
		exit(EXIT_FAILURE);
	}
}
