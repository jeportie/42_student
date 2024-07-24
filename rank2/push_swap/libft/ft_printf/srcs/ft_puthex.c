/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:35:31 by neleon            #+#    #+#             */
/*   Updated: 2023/12/21 19:46:17 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptohex(va_list ap, int *count)
{
	unsigned long	p;
	const char		*hex;

	hex = "0123456789abcdef";
	p = va_arg(ap, unsigned long);
	if (p == 0)
	{
		write(1, "(nil)", 5);
		*count += 5;
	}
	else
	{
		write(1, "0x", 2);
		*count += 2;
		ft_putbase(p, hex, count);
	}
}

void	ft_nbr_to_hex(va_list ap, char x, int *count)
{
	const char		*lower_hex;
	const char		*upper_hex;
	unsigned int	nb;

	lower_hex = "0123456789abcdef";
	upper_hex = "0123456789ABCDEF";
	nb = va_arg(ap, long);
	if (x == 'x')
		ft_putbase(nb, lower_hex, count);
	else if (x == 'X')
		ft_putbase(nb, upper_hex, count);
}

void	ft_putbase(unsigned long nb, const char *base, int *count)
{
	unsigned long	base_len;

	base_len = ft_strlen(base);
	if (nb >= base_len)
		ft_putbase(nb / base_len, base, count);
	ft_putchar_fd(base[nb % base_len], 1);
	*count += 1;
}
