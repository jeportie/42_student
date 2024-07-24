/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:40:23 by neleon            #+#    #+#             */
/*   Updated: 2023/12/14 00:27:26 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char *s, va_list ap, int *count)
{
	if (*s == '%' && *(s + 1) == '%')
	{
		write(1, "%", 1);
		*count += 1;
	}
	else if (*s == '%' && *(s + 1) == 'c')
		ft_putchar(ap, count);
	else if (*s == '%' && *(s + 1) == 's')
		ft_putstr(ap, count);
	else if (*s == '%' && (*(s + 1) == 'i' || *(s + 1) == 'd'))
		ft_itochar(ap, count);
	else if (*s == '%' && *(s + 1) == 'u')
		ft_uitochar(ap, count);
	else if (*s == '%' && *(s + 1) == 'p')
		ft_ptohex(ap, count);
	else if (*s == '%' && (*(s + 1) == 'x' || *(s + 1) == 'X'))
		ft_nbr_to_hex(ap, *(s + 1), count);
	else
		return (-1);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s != '%')
		{
			write(1, s, 1);
			count++;
		}
		else
		{
			ft_format(s, ap, &count);
			s++;
		}
		s++;
	}
	va_end(ap);
	return (count);
}

// int	main(void)
// {
// 	char *name = "Alice";
// 	size_t nb = 5;
// 	unsigned long unb = 255;
// 	ft_printf("Hello %c! You %%%%%% have %u new messages 
// %p.\n", '\0', nb, &name);
		// 	ft_printf("%d in hexa is : %X\n", unb, unb);
		// 	return (0);
		// }