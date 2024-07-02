/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:30:37 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 12:30:37 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_update_position(int keysym, int *y, int *x)
{
	if (keysym == XK_w || keysym == XK_Up)
		(*y)--;
	else if (keysym == XK_s || keysym == XK_Down)
		(*y)++;
	else if (keysym == XK_a || keysym == XK_Left)
		(*x)--;
	else if (keysym == XK_d || keysym == XK_Right)
		(*x)++;
	else
		return ;
}
