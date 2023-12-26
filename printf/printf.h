/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:11:49 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/26 20:13:37 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H


#include <stdarg.h>
#include "function_library/libft.h"

#define BUFFER_SIZE 2048

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
int				ft_check_format(t_format_spec spec);
void			ft_apply_width(t_format_spec spec, char *buffer, int *index, int content_len);
void			ft_apply_precision(t_format_spec spec, char *buffer, int *index, int content_len);
void			ft_handle_minus_flag(char *buffer, int *index);
void			ft_handle_zero_flag(char *buffer, int *index);
void			ft_handle_hash_flag(char *buffer, int *index);
void			ft_handle_space_flag(char *buffer, int *index);
void			ft_handle_plus_flag(char *buffer, int *index);
//Conversion functions
void			ft_handle_char(t_format_spec spec, va_list args, char *buffer, int *i);
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
