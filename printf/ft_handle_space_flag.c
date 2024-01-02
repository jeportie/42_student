/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_space_flag.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:25:19 by jeportie          #+#    #+#             */
/*   Updated: 2024/01/02 02:59:02 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_handle_space_flag(t_format_spec spec, int content, t_buffer *buf_info)
{
	if (!spec.flag_plus && content >= 0)
		ft_buffer_add(buf_info, ' ');
}
