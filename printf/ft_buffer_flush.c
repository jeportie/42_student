/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_flush.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:03:39 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/31 15:37:47 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_buffer_flush(t_buffer *buf_info)
{
	int	total_written;
	int written;

	total_written = 0;
	while (total_written < buf_info->index)
	{
		written = write(1, &buf_info->buffer[total_written], buf_info->index - total_written);
		if (written <= 0)
		{
			buf_info->nb_printed += total_written;
			buf_info->index = 0;
			buf_info->error = ERNOWRITE;
			return (0);
		}
		total_written += written;
	}
	buf_info->nb_printed += total_written;
	buf_info->index =  0;
	return (1);
}
