/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hexadecimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:18:44 by jeportie          #+#    #+#             */
/*   Updated: 2024/01/02 01:50:12 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_handle_hexadecimal(t_format_spec spec, va_list args, t_buffer *buf_info)
{
	int		content;
	char	*formatted_content;
	int		formatted_len;
	int		i;

	content = va_arg(args, unsigned int);
	if (spec.type == 'X')
		formatted_content = ft_ulltoa_base(content, "0123456789ABCDEF");
	if (spec.type == 'x')
		formatted_content = ft_ulltoa_base(content, "0123456789abcdef");
	if (!formatted_content)
	{
		buf_info->error = ERNOMEM;
		return (0);
	}
	formatted_len  = 0;
	while (formatted_content[formatted_len] 
			&& (spec.precision < 0 || formatted_len < spec.precision))
		formatted_len++;
	if (spec.flag_hash && content)
		formatted_len += 2;
	i = 0;
	if (!spec.flag_minus)
		ft_apply_width(spec, buf_info, formatted_len);
	ft_handle_hash_flag(spec, content, buf_info);
	while(i < formatted_len && formatted_content[i])
		ft_buffer_add(buf_info, formatted_content[i++]);	
	if (spec.flag_minus)
		ft_apply_width(spec, buf_info, formatted_len);
	free(formatted_content);
	return (1);
}
