/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 20:43:10 by jeportie          #+#    #+#             */
/*   Updated: 2024/01/05 02:53:22 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int	ft_handle_int(t_format_spec spec, va_list args, t_buffer *buf_info)
{
	long long	content;
	char		*formatted_content;
	int		formatted_len;
	int			i;


	i = 0;
	if (spec.type == 'i' || spec.type == 'd')
 	{
		content = (int)va_arg(args, int);
		formatted_content = ft_itoa((int)content);
	}
	if (spec.type == 'u')
	{
		content = (unsigned int)va_arg(args, unsigned int);
		formatted_content = ft_utoa_base((unsigned int)content, "0123456789");
	}
	if (!formatted_content)
	{
		buf_info->error = ERNOMEM;
		return (0);
	}
	if (spec.precision != -1)
		ft_apply_precision(spec, &formatted_content);
	formatted_len  = ft_strlen(formatted_content);
	if (!spec.flag_minus)
	{
		if (spec.flag_zero && formatted_content[0] == '-')
		{
			ft_buffer_add(buf_info, '-');
			i = 1;
		}
		ft_apply_width(spec, buf_info, formatted_len + (spec.flag_space || spec.flag_plus));
	}
	ft_handle_space_flag(spec, content, buf_info);
	ft_handle_plus_flag(spec, content, buf_info);
	while(formatted_content[i])
		ft_buffer_add(buf_info, formatted_content[i++]);	
	if (spec.flag_minus)
		ft_apply_width(spec, buf_info, formatted_len + (spec.flag_space || spec.flag_plus));
	free(formatted_content);
	return (1);
}
