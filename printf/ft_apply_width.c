/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:21:49 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/30 19:44:40 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_apply_width(t_format_spec spec, t_buffer *buf_info, int content_len)
{
	int		width;
	char	pad;

	width = spec.width;
	pad = ' ';
	if (spec.flag_zero)
		pad = '0';
	while (width > content_len)
	{
		ft_buffer_add(buf_info, pad);
		width--;
	}
}
