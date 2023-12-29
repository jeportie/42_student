/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 20:43:10 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/29 22:02:19 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_handle_int(t_format_spec spec, va_list args, char *buffer, int *index)
{
	int		content;
	char	*formatted_content;
	int		formatted_len;
	int		i;

	if (spec.type == 'd' || spec.type == 'i')
	{
		content = (int)va_arg(args, int);
		formatted_content = ft_itoa(content);
	}
	if (spec.type == 'u')
	{
		content = (unsigned int)va_arg(args, unsigned int);
		formatted_content = ft_ulltoa_base((unsigned long long)content, "0123456789");
	}
	formatted_len = ft_strlen(formatted_content);
	i = 0;
	if (spec.precision > 0)
		formatted_len = spec.precision;
	if (spec.flag_minus)
	{
		while(formatted_content[i] && i < formatted_len)
		{
			ft_handle_space_flag(spec, buffer, index);
			ft_handle_plus_flag(spec, content,  buffer, index);
			ft_buffer_add(buffer, index, formatted_content[i]);	
			i++;
		}
	}
	ft_apply_width(spec, buffer, index, formatted_len);
	if (!spec.flag_minus)
	{
		while(formatted_content[i] && i < formatted_len)
		{
			ft_handle_space_flag(spec, buffer, index);
			ft_handle_plus_flag(spec, content, buffer, index);
			ft_buffer_add(buffer, index, formatted_content[i]);	
			i++;
		}
	}
	free(formatted_content);
}
