/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:35:53 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/08 00:36:00 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdio.h>

void	ft_check_malloc(void *ptr, const char *error_message)
{
	if (!ptr)
	{
		perror(error_message);
		gc_cleanup();
		exit(EXIT_FAILURE);
	}
}
