/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttxt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:47:47 by neleon            #+#    #+#             */
/*   Updated: 2023/12/14 00:22:01 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(va_list ap, int *count)
{
	char	c;

	c = va_arg(ap, int);
	write(1, &c, sizeof(char));
	*count += 1;
}

void	ft_putstr(va_list ap, int *count)
{
	char	*s;

	s = va_arg(ap, char *);
	if (!s)
	{
		write(1, "(null)", 6);
		*count += 6;
	}
	else
	{
		while (*s)
		{
			write(1, s, sizeof(char));
			*count += 1;
			s++;
		}
	}
}
