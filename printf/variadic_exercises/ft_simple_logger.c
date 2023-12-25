/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_logger.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:07:20 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/25 18:08:37 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_parse_arg(va_list args, char *buffer, int *index, char c)
{
	char	*str;

	if (c == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 's')
	{
		str = va_arg(args, char *);
		if (str)
			ft_putstr_fd(str, 1);
		else 
			ft_putstr_fd("(null)", 1);
	}
	else if (c == '%')
		ft_buffer_add(buffer, index, '%');
	else
	{
		ft_buffer_add(buffer, index, '%');
		ft_buffer_add(buffer, index, c);
	}
}

void	ft_simple_logger(const char *format, ...)
{
	va_list	args;
	int		i;
	char	buffer[BUFFER_SIZE];
	int		index;

	va_start(args, format);
	i = 0;
	index = 0;
	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			ft_parse_arg(args, buffer, &index, format[i]);
			i++;
		}
		else
			ft_buffer_add(buffer, &index, format[i]);
		i++;
	}
	ft_buffer_flush(buffer, &index);
	va_end(args);
}

