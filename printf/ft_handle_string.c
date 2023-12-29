/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:56:22 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/29 22:57:05 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_handle_string(t_format_spec spec, va_list args, char *buffer, int *index)
{
	char	*str;
	int		content_len;
	int		i;

	str = (char *)va_arg(args, char *);
	content_len = ft_strlen(str);
	i = 0;
	if (spec.precision > 0)
		content_len = spec.precision;
	if (spec.flag_minus)
	{
		while(str[i] && i < content_len)
		{
			ft_buffer_add(buffer, index, str[i]);	
			i++;
		}
	}
	ft_apply_width(spec, buffer, index, content_len);
	if (!spec.flag_minus)
	{
		while(str[i] && i < content_len)
		{
			ft_buffer_add(buffer, index, str[i]);	
			i++;
		}
	}
}
