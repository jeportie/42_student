/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_space_flag.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:25:19 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/31 16:02:42 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_handle_space_flag(t_format_spec spec, t_buffer *buf_info)
{
	char	last_char;
	
	if (buf_info->index == 0)
		last_char = buf_info->buf_last;
	else
		last_char = buf_info->buffer[buf_info->index - 1];
	if (spec.flag_space && last_char != '-' && last_char != '+')
		ft_buffer_add(buf_info, ' ');
}
