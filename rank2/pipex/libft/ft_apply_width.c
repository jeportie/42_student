/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:21:49 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/27 18:09:03 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

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
	if (spec.flag_plus && spec.width && content_len < spec.width)
		ft_buffer_add(buf_info, pad);
}
