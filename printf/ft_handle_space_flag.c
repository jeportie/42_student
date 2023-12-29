/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_space_flag.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:25:19 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/29 23:00:17 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
**ATENTION ! SI + ou - est sur le dernier element qui a ete flush, risque de bug car pas dans la condition.
*/
void	ft_handle_space_flag(t_format_spec spec, char *buffer, int *index)
{
	if (spec.flag_space && (index > 0 && (buffer[*index - 1] != '-' || buffer[*index - 1] != '+')))
		ft_buffer_add(buffer, index, ' ');
}
