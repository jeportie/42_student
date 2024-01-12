/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:11:49 by jeportie          #+#    #+#             */
/*   Updated: 2024/01/12 20:36:47 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_prepare_pointer(va_list args, char **adresse,
		t_buffer *buf_info)
{
	void	*ptr;

	ptr = (void *)va_arg(args, void *);
	if (!ptr)
		*adresse = "0";
	else
	{
		*adresse = ft_ulltoa_base((unsigned long long)ptr, "0123456789abcdef");
		if (!*adresse)
		{
			buf_info->error = ERNOMEM;
			return (0);
		}
	}
	return (1);
}

static void	ft_process_pointer(t_format_spec spec, char *adresse,
		t_buffer *buf_info)
{
	int	content_len;
	int	i;

	content_len = ft_strlen(adresse) + 2;
	if (spec.flag_plus)
		content_len++;
	if (!spec.flag_minus)
		ft_apply_width(spec, buf_info, content_len);
	ft_handle_space_flag(spec, (unsigned long long)adresse, buf_info);
	ft_handle_plus_flag(spec, (unsigned long long)adresse, buf_info);
	ft_buffer_add(buf_info, '0');
	ft_buffer_add(buf_info, 'x');
	i = 0;
	while (adresse[i])
		ft_buffer_add(buf_info, adresse[i++]);
	if (spec.flag_minus)
		ft_apply_width(spec, buf_info, content_len);
}

int	ft_handle_pointer(t_format_spec spec, va_list args, t_buffer *buf_info)
{
	char	*adresse;

	if (!ft_prepare_pointer(args, &adresse, buf_info))
		return (0);
	ft_process_pointer(spec, adresse, buf_info);
	if (adresse[0] != '0')
		free(adresse);
	return (1);
}
