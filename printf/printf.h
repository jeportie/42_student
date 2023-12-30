/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:11:49 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/30 19:10:59 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H


#include <stdarg.h>
#include <stdlib.h>
#include "function_library/libft.h"

#define BUFFER_SIZE 2048

typedef struct s_buffer
{
	char	*buffer;
	int		index;
	int		nb_printed;
}			t_buffer;

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
//type conversion functions
char			*ft_ulltoa_base(unsigned long long nbr, char *base);
//format spec functions
t_format_spec	ft_parse_format(const char **format);
int				ft_check_format(t_format_spec spec);
void			ft_apply_width(t_format_spec spec, t_buffer *buf_info, int content_len);
void			ft_handle_hash_flag(t_format_spec spec, int content, t_buffer *buf_info);
void			ft_handle_space_flag(t_format_spec spec, t_buffer *buf_info);
void			ft_handle_plus_flag(t_format_spec spec, int content, t_buffer *buf_info);
//Conversion functions
void			ft_handle_char(t_format_spec spec, va_list args, t_buffer *buf_info);
void			ft_handle_string(t_format_spec spec, va_list args, t_buffer *buf_info);
void			ft_handle_pointer(t_format_spec spec, va_list args, t_buffer *buf_info);
void			ft_handle_int(t_format_spec spec, va_list args, t_buffer *buf_info);
void			ft_handle_hexadecimal(t_format_spec spec, va_list args, t_buffer *buf_info);
//buffer management
void			ft_buffer_add(t_buffer *buf_info, char c);
int				ft_buffer_flush(t_buffer *buf_info);
#endif /*PRINTF_H*/
