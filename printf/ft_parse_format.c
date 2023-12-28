/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:29:21 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/28 15:35:38 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_isflag(char c)
{
	if (c == '-' || (c >= '0' && c <= '9') || c == '#' || c == ' ' || c == '+' 
			|| c == '.')
		return (1);
	return (0);
}

static int ft_isconvert_spec(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' 
			|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static char	*ft_find_end(const char *start, t_format_spec *spec)
{
	char	*ptr;

	ptr = (char *)start;
	while (!ft_isconvert_spec(*ptr))
		ptr++;
	spec->type = *ptr;
	return (ptr);
}

static void	ft_parse_width(const char *format, t_format_spec *spec, size_t *i)
{
	if (format[*i] >= '0' && format[*i] <= '9')
	{
		while (format[*i] >= '0' && format[*i] <= '9')
		{
			spec->width = spec->width * 10 + (format[*i] - '0');
			(*i)++;
		}
	}
}

static void	ft_parse_precision(const char *format, t_format_spec *spec, size_t *i)
{
	if (format[*i] == '.')
	{
		(*i)++;
		spec->precision = 0;
		while (format[*i] >= '0' && format[*i] <= '9')
		{
			spec->precision = spec->precision * 10 + (format[*i] - '0');
			(*i)++;
		}
	}
}

static void	ft_parse_flags(const char *format, t_format_spec *spec)
{
	size_t	i;

	i = 0;
	while(ft_isflag(format[i]) && format[i] != spec->type)
	{
		if ((format[0] == '0' || (format[0] == '-' && format[1] == '0')) && spec->type != 's')
			spec->flag_zero = 1;
		else if (*format == '-')
			spec->flag_minus = 1;
		else if (*format == '#')
			spec->flag_hash = 1;
		else if (*format == ' ')
			spec->flag_space = 1;
		else if (*format == '+')
			spec->flag_plus = 1;
		else if (*format >= '0' && *format <= '9')
			ft_parse_width(format, spec, &i);	
		else if (*format == '.')
			ft_parse_precision(format, spec, &i);
		i++;
	}
}

t_format_spec	ft_parse_format(const char **format)
{
	t_format_spec	spec;
	const	char	*format_spec_end;

	spec.width = 0;
	spec.precision = -1;
	spec.flag_minus = 0;
	spec.flag_zero = 0;
	spec.flag_hash = 0;
	spec.flag_space = 0;
	spec.flag_plus = 0;
	spec.type = '\0';
	(*format)++;
	format_spec_end = ft_find_end(*format, &spec);
	ft_parse_flags(*format, &spec);
	*format = format_spec_end; 
	return (spec);
}


ft_printf("%-010.5i), var")
