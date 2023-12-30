/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hexadecimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:18:44 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/30 19:41:25 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_handle_hexadecimal(t_format_spec spec, va_list args, t_buffer *buf_info)
{
	int		content;
	char	*formatted_content;
	int		formatted_len;
	int		i;

	content = (int)va_arg(args, int);
	if (spec.type == 'X')
		formatted_content = ft_ulltoa_base(content, "0123456789ABCDEF");
	if (spec.type == 'x')
		formatted_content = ft_ulltoa_base(content, "0123456789abcdef");
	formatted_len = ft_strlen(formatted_content);
	i = 0;
	if (spec.precision > 0)
		formatted_len = spec.precision;
	if (spec.flag_minus)
	{
		ft_handle_hash_flag(spec, content, buf_info);
		while(formatted_content[i] && i < formatted_len)
		{
			ft_buffer_add(buf_info, formatted_content[i]);	
			i++;
		}
	}
	ft_apply_width(spec, buf_info, formatted_len);
	if (!spec.flag_minus)
	{
		ft_handle_hash_flag(spec, content, buf_info);
		while(formatted_content[i] && i < formatted_len)
		{
			ft_buffer_add(buf_info, formatted_content[i]);	
			i++;
		}
	}
	free(formatted_content);
}
