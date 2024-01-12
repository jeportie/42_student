/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:03:11 by jeportie          #+#    #+#             */
/*   Updated: 2024/01/12 19:46:39 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_buffer_add(t_buffer *buf_info, char c)
{
	if (buf_info->error)
		return ;
	if (buf_info->index >= BUFFER_SIZE)
	{
		buf_info->buf_last = buf_info->buffer[buf_info->index - 1];
		if (!ft_buffer_flush(buf_info))
		{
			buf_info->error = ERNOWRITE;
			return ;
		}
	}
	buf_info->buffer[buf_info->index] = c;
	buf_info->index++;
}
