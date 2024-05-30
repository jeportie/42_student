/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:11:49 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/21 14:26:03 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif
# define TEST 1

typedef struct s_buffer
{
	char	*buffer;
	int		index;
	int		nb_printed;
	int		error;
	char	buf_last;
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
	int			error;
}				t_format_spec;

typedef enum e_error
{
	NOERR,
	ERNOWRITE,
	ERNOMEM,
	ERNOFORMAT,
}	t_error;

extern const char	*g_perror[];

int				ft_printf(const char *format, ...);
int				ft_isflag(char c);
int				ft_isconvert_spec(char c);

//type conversion functions
char			*ft_utoa_base(unsigned int nbr, char *base);
char			*ft_ulltoa_base(unsigned long long nbr, char *base);
int				ft_nbr_len(unsigned long long nbr, int base_len);
//format spec functions
t_format_spec	ft_parse_format(const char **format);
void			ft_parse_flags(const char *format, t_format_spec *spec);

int				ft_check_format(t_format_spec *spec);
void			ft_apply_width(t_format_spec spec, t_buffer *buf_info,
					int content_len);
void			ft_apply_precision(t_format_spec spec,
					char **formatted_content);
void			ft_handle_hash_flag(t_format_spec spec, int content,
					t_buffer *buf_info);
void			ft_handle_space_flag(t_format_spec spec, int content,
					t_buffer *buf_info);
void			ft_handle_plus_flag(t_format_spec spec, int content,
					t_buffer *buf_info);
//Conversion functions
void			ft_handle_char(t_format_spec spec, va_list args,
					t_buffer *buf_info);
void			ft_handle_string(t_format_spec spec, va_list args,
					t_buffer *buf_info);
int				ft_handle_pointer(t_format_spec spec, va_list args,
					t_buffer *buf_info);
int				ft_handle_int(t_format_spec spec, va_list args,
					t_buffer *buf_info);
int				ft_handle_hexadecimal(t_format_spec spec, va_list args,
					t_buffer *buf_info);
//buffer management
void			ft_buffer_add(t_buffer *buf_info, char c);
int				ft_buffer_flush(t_buffer *buf_info);
#endif /*PRINTF_H*/
