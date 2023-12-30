/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_flush.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:03:39 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/30 19:00:32 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_buffer_flush(t_buffer *buf_info)
{
	int written;

	written = write(1, buf_info->buffer, buf_info->index);
	if (written == -1)
	{
		buf_info->index = 0;
		return (0);
	}
	buf_info->nb_printed += written;
	buf_info->index =  0;
	return (1);
}
