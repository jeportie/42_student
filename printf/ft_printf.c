/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:05:57 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/31 16:30:43 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_convert_spec(t_format_spec spec, va_list args, t_buffer *buf_info)
{
	if (spec.type == 'c')
		ft_handle_char(spec, args, buf_info);
	else if (spec.type == 's')
		ft_handle_string(spec, args, buf_info);
	else if (spec.type == 'p')
		ft_handle_pointer(spec, args, buf_info);
	else if (spec.type == 'd' || spec.type == 'i' || spec.type == 'u')
		ft_handle_int(spec, args, buf_info);
	else if (spec.type == 'x' || spec.type == 'X')
		ft_handle_hexadecimal(spec, args, buf_info);
	else if (spec.type == '%')
		ft_buffer_add(buf_info, '%');
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	t_format_spec	spec;
	t_buffer		buf_info;
	char			buffer[BUFFER_SIZE];

	buf_info.buffer = buffer;
	buf_info.index = 0;
	buf_info.nb_printed = 0;
	buf_info.error = 0;
	buf_info.buf_last = '\0';
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			spec = ft_parse_format(&format);
			if (!spec.type)
			{
				ft_putstr_fd((char *)g_perror[ERNOWRITE], 2);
				return (-1);
			}
			if (ft_check_format(spec))
				ft_convert_spec(spec, args, &buf_info);
			else
			{
				ft_putstr_fd((char *)g_perror[ERNOFORMAT], 2);
				return (-1);
			}
		}
		else
			ft_buffer_add(&buf_info, *format);
		format++;
	}
	va_end(args);
	if (!ft_buffer_flush(&buf_info))
		return (-1);
	return (buf_info.nb_printed);
}
