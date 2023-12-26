/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:11:49 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/26 01:09:14 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H


#include <stdarg.h>
#include "function_library/libft.h"

#define BUFFER_SIZE 1024

typedef struct s_format_spec
{
	int			width;
	int			precision;
	int			flag_minus;
	int			flag_zero;
	int			flag_hash;
	int			flag_space;
	int			flag_plus;
	char		type;
}				t_format_spec;

int				ft_printf(const char *format, ...);
//format spec functions
t_format_spec	ft_parse_format(const char **format);
//Conversion functions
void			ft_handle_char(t_format_spec spec, va_list args, char *buffer, int *index);
void			ft_handle_string(t_format_spec spec, va_list args, char *buffer, int *index);
void			ft_handle_pointer(t_format_spec spec, va_list args, char *buffer, int *index);
void			ft_handle_int(t_format_spec spec, va_list args, char *buffer, int *index);
void			ft_handle_unsigned_int(t_format_spec spec, va_list args, char *buffer, int *index);
void			ft_handle_hexadecimal(t_format_spec spec, va_list args, char *buffer, int *index);
void			ft_handle_percent(t_format_spec spec, va_list args, char *buffer, int *index);
//buffer management
void			ft_buffer_add(char *buffer, int *index, char c);
void			ft_buffer_flush(char *buffer, int *index);

#endif /*PRINTF_H*/
