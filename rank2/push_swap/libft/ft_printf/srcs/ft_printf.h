/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:42:15 by neleon            #+#    #+#             */
/*   Updated: 2024/03/23 16:02:26 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

void	ft_putstr(va_list ap, int *count);
void	ft_putchar(va_list ap, int *count);
void	ft_putnbr(long nb, int *count);
void	ft_itochar(va_list ap, int *count);
void	ft_uitochar(va_list ap, int *count);
void	ft_putbase(unsigned long nb, const char *base, int *count);
void	ft_ptohex(va_list ap, int *count);
void	ft_nbr_to_hex(va_list ap, char x, int *count);
int		ft_printf(const char *s, ...);
int		ft_format(const char *s, va_list ap, int *count);

#endif