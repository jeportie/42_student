/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_average.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:08:51 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/24 14:15:15 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	ft_average(int count, ...)
{
	va_list	args;
	int		sum;
	int		i;

	if (!count)
		return (0);
	va_start(args, count);
	i = 0;
	sum = 0;
	while (i < count)
	{
		sum += va_arg(args, int);
		i++;
	}
	va_end(args);
	return (sum / count);
}
