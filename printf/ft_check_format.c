/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:02:54 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/26 19:59:32 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_check_format(t_format_spec spec)
{
	if (spec.type == 'c')
		return (spec.width >= 0 && spec.precision == -1 && !spec.flag_hash 
				&& !spec.flag_space && !spec.flag_plus);
	else if (spec.type == 's')
		return (spec.width >= 0 && !spec.flag_zero && !spec.flag_hash 
				&& !spec.flag_space && !spec.flag_plus);
	else if (spec.type == 'p')
		return (spec.width >= 0 && !spec.flag_hash && !spec.flag_space 
				&& !spec.flag_plus && spec.precision == -1);
	else if (spec.type == 'd' || spec.type == 'i' || spec.type == 'u')
		return (spec.width >= 0 && !spec.flag_hash);
	else if (spec.type == 'x' || spec.type == 'X')
		return (spec.width >= 0 && !spec.flag_space && !spec.flag_plus);
	else if (spec.type == '%')
		return (spec.width >= 0 && spec.precision == -1 && !spec.flag_minus 
				&& !spec.flag_zero && !spec.flag_hash && !spec.flag_space 
				&& !spec.flag_plus);
	else
		return (0);
}
