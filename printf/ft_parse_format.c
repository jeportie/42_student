/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:29:21 by jeportie          #+#    #+#             */
/*   Updated: 2024/01/05 04:14:59 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_isflag(char c)
{
	if (ft_strchr("0123456789 #+-.", c))
		return (1);
	return (0);
}

static int ft_isconvert_spec(char c)
{
	if (ft_strchr("cspdiuxX%", c))
		return (1);
	return (0);
}

static char	*ft_find_end(const char *start, t_format_spec *spec)
{
	char	*ptr;

	if (!start)
		return (NULL);
	ptr = (char *)start;
	while (*ptr && (ft_isflag(*ptr) || ft_isconvert_spec(*ptr)))
	{
		if (ft_isconvert_spec(*ptr))
		{
			spec->type = *ptr;
			return (ptr);
		}
		ptr++;
	}
	return (NULL);
}

static void	ft_parse_width(const char *format, t_format_spec *spec, size_t *i)
{
	spec->width = 0;
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		spec->width = spec->width * 10 + (format[*i] - '0');
		(*i)++;
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
		if ((format[i] == '0' && !spec->flag_minus && !spec->width))
		{
			spec->flag_zero = 1;
			i++;
		}
		else if (format[i] == '-')
		{
			spec->flag_minus = 1;
			spec->flag_zero = 0;
			i++;
		}
		else if (format[i] == '+')
		{
			spec->flag_plus = 1;
			spec->flag_space = 0;
			i++;
		}
		else if (format[i] == ' ' && !spec->flag_plus)
		{
			spec->flag_space = 1;
			i++;
		}
		else if (format[i] == '#')
		{
			spec->flag_hash = 1;
			i++;
		}
		else if (format[i] >= '0' && format[i] <= '9')
			ft_parse_width(format, spec, &i);	
		else if (format[i] == '.' && spec->type != 'p' && spec->type != 'c')
			ft_parse_precision(format, spec, &i);
		else 
		{
			spec->error = ERNOFORMAT;
			break;
		}
	}
}

t_format_spec	ft_parse_format(const char **format)
{
	t_format_spec	spec;
	char	*end;

	ft_memset(&spec, 0, sizeof(t_format_spec));
	spec.precision = -1;
	if (!format || !*format || **format != '%')
		return (spec);
	(*format)++;
	end = ft_find_end(*format, &spec);
	if (!end)
	{
		spec.error = ERNOFORMAT;
		return (spec);
	}
	ft_parse_flags(*format, &spec);
	*format = end; 
	return (spec);
}

/*
Breakdown:
Flag Checking (ft_isflag): Utilizes ft_strchr to efficiently check if a 
character is a valid flag. This approach is concise and easy to understand.

Conversion Specifier Checking (ft_isconvert_spec): Similar to ft_isflag, this 
function efficiently checks for valid conversion specifiers.

Finding the Format Specifier End (ft_find_end): Iterates through the string 
until it finds a valid conversion specifier, handling the case where the 
starting pointer is NULL.

Parsing Width and Precision (ft_parse_width and ft_parse_precision): These 
functions correctly parse numeric values for width and precision from the 
format string.

Parsing Flags (ft_parse_flags): This function is now well-structured to handle 
various flags and their interactions, correctly prioritizing them and setting 
error codes when unexpected characters are encountered.

Main Parsing Function (ft_parse_format): Orchestrates the parsing process, 
setting up the t_format_spec structure, and handling errors gracefully.

Memory Initialization: You're using ft_memset to initialize the spec structure,
which is a good practice to avoid any undefined behavior from uninitialized 
values.

Error Handling: Your code sets spec.error = ERNOFORMAT when unexpected 
characters are encountered or when no valid conversion specifier is found, 
which is excellent for robustness and error tracking.

Pointer Checks: You're checking the validity of the format pointer at the 
beginning of ft_parse_format, which is crucial to prevent segmentation faults.

Consistency and Clarity: The code is consistent in its use of indexing 
(format[i]) throughout the parsing process, making it easier to follow 
and understand.
*/
