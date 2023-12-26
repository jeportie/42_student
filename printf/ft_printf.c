/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:05:57 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/26 18:39:43 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_convert_spec(t_format_spec spec, va_list args, char *buffer, int *index)
{
	if (spec.type == 'c')
		ft_handle_char(spec, args, buffer, index);
	else if (spec.type == 's')
		ft_handle_string(spec, args, buffer, index);
	else if (spec.type == 'p')
		ft_handle_pointer(spec, args, buffer, index);
	else if (spec.type == 'd' || spec.type == 'i')
		ft_handle_int(spec, args, buffer, index);
	else if (spec.type == 'u')
		ft_handle_unsigned_int(spec, args, buffer, index);
	else if (spec.type == 'x' || spec.type == 'X')
		ft_handle_hexadecimal(spec, args, buffer, index);
	else if (spec.type == '%')
		ft_handle_percent(spec, args, buffer, index);
}

int	ft_printf(const char *format, ...)
{
	int				nb_printed;
	va_list			args;
	t_format_spec	spec;
	char			buffer[BUFFER_SIZE];
	int				index;

	index = 0;
	va_start(args, format);
	nb_printed = 0;
	while (*format)
	{
		if (*format == '%')
		{
			spec = ft_parse_format(&format);
			if (ft_check_format(spec))
				ft_convert_spec(spec, args, buffer, &index);
			else
				return (-1);
		}
		else
			ft_buffer_add(buffer, &index, *format);
		format++;
	}
	va_end(args);
	ft_buffer_flush(buffer, &index);
	return (nb_printed);
}
