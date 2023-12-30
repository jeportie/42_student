/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:56:22 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/30 19:50:12 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_handle_string(t_format_spec spec, va_list args, t_buffer *buf_info)
{
	char	*str;
	int		content_len;
	int		i;

	str = (char *)va_arg(args, char *);
	content_len = ft_strlen(str);
	i = 0;
	if (spec.precision > 0)
		content_len = spec.precision;
	if (spec.flag_minus)
	{
		while(str[i] && i < content_len)
		{
			ft_buffer_add(buf_info, str[i]);	
			i++;
		}
	}
	ft_apply_width(spec, buf_info, content_len);
	if (!spec.flag_minus)
	{
		while(str[i] && i < content_len)
		{
			ft_buffer_add(buf_info, str[i]);	
			i++;
		}
	}
}
