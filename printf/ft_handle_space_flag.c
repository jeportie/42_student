/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_space_flag.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:25:19 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/30 19:49:09 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
**ATENTION ! SI + ou - est sur le dernier element qui a ete flush, risque de bug car pas dans la condition.
*/
void	ft_handle_space_flag(t_format_spec spec, t_buffer *buf_info)
{
	if (spec.flag_space && (buf_info->index > 0
			&& (buf_info->buffer[buf_info->index - 1] != '-'
			|| buf_info->buffer[buf_info->index - 1] != '+')))
		ft_buffer_add(buf_info, ' ');
}
