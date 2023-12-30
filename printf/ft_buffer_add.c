/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:03:11 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/30 18:55:23 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_buffer_add(t_buffer *buf_info, char c)
{
	if (buf_info->index >= BUFFER_SIZE - 1)
	{
		if (!ft_buffer_flush(buf_info))
			return ;
	}
	buf_info->buffer[buf_info->index] = c;
	buf_info->index++;
}
