/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:05:57 by jeportie          #+#    #+#             */
/*   Updated: 2024/01/04 23:17:54 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_convert_spec(t_format_spec spec, va_list args, t_buffer *buf_info)
{
	if (spec.type == 'c')
		ft_handle_char(spec, args, buf_info);
	else if (spec.type == 's')
		ft_handle_string(spec, args, buf_info);
	else if (spec.type == 'p')
	{
		if (!ft_handle_pointer(spec, args, buf_info))
			return (0);
	}
	else if (spec.type == 'd' || spec.type == 'i' || spec.type == 'u')
	{
		if (!ft_handle_int(spec, args, buf_info))
			return (0);
	}
	else if (spec.type == 'x' || spec.type == 'X')
	{
		if (!ft_handle_hexadecimal(spec, args, buf_info))
			return (0);
	}
	else if (spec.type == '%')
		ft_buffer_add(buf_info, '%');
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	t_format_spec	spec;
	t_buffer		buf_info;
	char			buffer[BUFFER_SIZE];

	ft_memset(&buf_info, 0, sizeof(t_buffer));
	buf_info.buffer = buffer;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			spec = ft_parse_format(&format);
			if (!spec.type)
			{
				ft_putstr_fd((char *)g_perror[spec.error], 2);
				return (-1);
			}
			if (ft_check_format(spec))
			{
				if(!ft_convert_spec(spec, args, &buf_info))
				{
					ft_putstr_fd((char *)g_perror[buf_info.error], 2);
					return (-1);
				}
			}
			else
			{
				ft_putstr_fd((char *)g_perror[spec.error], 2);
				return (-1);
			}
		}
		else
			ft_buffer_add(&buf_info, *format);
		format++;
	}
	va_end(args);
	if (!ft_buffer_flush(&buf_info))
	{
		ft_putstr_fd((char *)g_perror[buf_info.error], 2);
		return (-1);
	}
	return (buf_info.nb_printed);
}
