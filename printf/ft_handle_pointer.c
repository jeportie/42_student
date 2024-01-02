/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:22:11 by jeportie          #+#    #+#             */
/*   Updated: 2024/01/02 01:38:46 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_handle_pointer(t_format_spec spec, va_list args, t_buffer *buf_info)
{
	void	*ptr;
	char	*adresse;
	int		content_len;
	int		i;

	ptr = (void *)va_arg(args, void *);
	if (!ptr)
		adresse = "0";
	else
	{
		adresse = ft_ulltoa_base((unsigned long long)ptr, "0123456789abcdef");
		if (!adresse)
		{
			buf_info->error = ERNOMEM;
			return (0);
		}
	}
	content_len = ft_strlen(adresse) + 2;
	if (!spec.flag_minus)
		ft_apply_width(spec, buf_info, content_len);
	ft_buffer_add(buf_info, '0');
	ft_buffer_add(buf_info, 'x');
	i = 0;
	while(adresse[i])
		ft_buffer_add(buf_info, adresse[i++]);
	if (spec.flag_minus)
		ft_apply_width(spec, buf_info, content_len);
	if (ptr)
		free(adresse);
	return (1);
}
