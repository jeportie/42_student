/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:29:21 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/26 00:25:39 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_isflag(char c)
{
	if (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+')
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

static void	ft_parse_flags(const char **format, t_format_spec *spec)
{
	while(ft_isflag(**format))
	{
		if (**format == '-')
			spec->flag_minus = 1;
		else if (**format == '0')
			spec->flag_zero = 1;
		else if (**format == '#')
			spec->flag_hash = 1;
		else if (**format == ' ')
			spec->flag_space = 1;
		else if (**format == '+')
			spec->flag_plus = 1;
		(*format)++;
	}
}

static void	ft_parse_width(const char **format, t_format_spec *spec)
{
	if (**format >= '0' && **format <= '9')
	{
		while (**format >= '0' && **format <= '9')
		{
			spec->width = spec->width * 10 + (**format - '0');
			(*format)++;
		}
	}
}

static void	ft_parse_precision(const char **format, t_format_spec *spec)
{
	if (**format == '.')
	{
		(*format)++;
		spec->precision = 0;
		while (**format >= '0' && **format <= '9')
		{
			spec->precision = spec->precision * 10 + (**format - '0');
			(*format)++;
		}
	}
}
static void	ft_parse_conversion(const char **format, t_format_spec *spec)
{
	if (ft_isconvert_spec(**format))
	{
		spec->type = **format;
		(*format)++;
	}
}

t_format_spec	ft_parse_format(const char **format)
{
	t_format_spec	spec;

	spec.width = 0;
	spec.precision = -1;
	spec.flag_minus = 0;
	spec.flag_zero = 0;
	spec.flag_hash = 0;
	spec.flag_space = 0;
	spec.flag_plus = 0;
	spec.type = '\0';
	(*format)++;
	ft_parse_flags(format, &spec);
	ft_parse_width(format, &spec);
	ft_parse_precision(format, &spec);
	ft_parse_conversion(format, &spec);
	return (spec);
}
