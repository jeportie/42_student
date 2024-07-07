/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:34:20 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/08 00:36:08 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdio.h>

void	ft_check_fd(int fd, const char *error_message)
{
	if (fd == -1)
	{
		perror(error_message);
		gc_cleanup();
		exit(EXIT_FAILURE);
	}
}
