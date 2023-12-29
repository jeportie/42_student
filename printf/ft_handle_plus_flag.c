/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_plus_flag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:19:16 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/29 21:23:50 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_handle_plus_flag(t_format_spec spec, int content, char *buffer, int *index)
{
	if (spec.flag_plus)
	{
		if (content < 0)
			ft_buffer_add(buffer, index, '-');
		else
			ft_buffer_add(buffer, index, '+');
	}
}
