/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:03:11 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/25 18:03:34 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_buffer_add(char *buffer, int *index, char c)
{
	if (*index >= BUFFER_SIZE - 1)
		ft_buffer_flush(buffer, index);
	buffer[*index] = c;
	(*index)++;
}
