/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:22:11 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/30 19:45:48 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_handle_pointer(t_format_spec spec, va_list args, t_buffer *buf_info)
{
	void	*ptr;
	char	*adresse;
	int		content_len;
	int		i;

	ptr = (void *)va_arg(args, void *);
	adresse = ft_ulltoa_base((unsigned long long)ptr, "0123456789abcdef");
	content_len = ft_strlen(adresse);
	i = 0;
	if (spec.flag_minus)
	{
		while(adresse[i])
		{
			ft_buffer_add(buf_info, adresse[i]);	
			i++;
		}
	}
	ft_apply_width(spec, buf_info, content_len);
	if (!spec.flag_minus)
	{
		while(adresse[i])
		{
			ft_buffer_add(buf_info, adresse[i]);	
			i++;
		}
	}
	free(adresse);
}
