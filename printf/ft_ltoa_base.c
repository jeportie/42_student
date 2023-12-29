/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:07:17 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/29 21:52:57 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_fill_base(long nbr, int size, char *base, char *res)
{
	int	len;
	int	i;

	len = ft_strlen(base);
	i = size - 1;
	if (nbr == 0)
		res[i] = base[0];
	if (nbr < 0)
	{
		res[0] = '-';
		nbr *= -1;
	}
	while (nbr)
	{
		res[i] = base[nbr % len];
		i -= 1;
		nbr /= len;
	}
	res[size] = '\0';
	return (res);
}

char	*ft_ltoa_base(long nbr, char *base)
{
	int			len;
	int			size;
	char		*res;
	long		nbr_base;

	len = ft_strlen(base);
	size = 0;
	if (nbr <= 0)
		size++;
	nbr_base = nbr;
	while (nbr_base)
	{
		nbr_base /= len;
		size++;
	}
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	return (ft_fill_base(nbr, size, base, res));
}
