/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:16:08 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/24 14:16:39 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	ft_print_strings(int count, ...)
{
	va_list args;
	char	*str;
	int		i;

	if (!count)
		return ;
	va_start(args, count);
	i = 0;
	while (i < count)
	{
		str = va_arg(args, char *);
		if (str)
			ft_putstr_fd(str, 1);
		i++;
	}
	va_end(args);
}
