/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 20:43:10 by jeportie          #+#    #+#             */
/*   Updated: 2024/01/02 02:55:27 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_handle_int(t_format_spec spec, va_list args, t_buffer *buf_info)
{
	int		content;
	char	*formatted_content;
	int		formatted_len;
	int		i;

	if (spec.type == 'd' || spec.type == 'i')
	{
		content = (int)va_arg(args, int);
		formatted_content = ft_itoa(content);
	}
	if (spec.type == 'u')
	{
		content = (unsigned int)va_arg(args, unsigned int);
		formatted_content = ft_ulltoa_base(content, "0123456789");
	}
	if (!formatted_content)
	{
		buf_info->error = ERNOMEM;
		return (0);
	}
	formatted_len = 0;
	while (formatted_content[formatted_len] 
			&& (spec.precision < 0 || formatted_len < spec.precision))
		formatted_len++;
	i = 0;
	if (!spec.flag_minus)
		ft_apply_width(spec, buf_info, formatted_len + (spec.flag_space || spec.flag_plus));
	ft_handle_space_flag(spec, content, buf_info);
	ft_handle_plus_flag(spec, content, buf_info);
	while(i < formatted_len && formatted_content[i])
		ft_buffer_add(buf_info, formatted_content[i++]);	
	if (spec.flag_minus)
		ft_apply_width(spec, buf_info, formatted_len + (spec.flag_space || spec.flag_plus));
	free(formatted_content);
	return (1);
}
