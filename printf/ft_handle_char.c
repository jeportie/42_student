/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:12:16 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/26 23:33:47 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_handle_char(t_format_spec spec, va_list args, char *buffer,
		int *index)
{
	char	c;
	char	*to_buffer;
	

	c = (char)va_arg(args, int);
	
}

