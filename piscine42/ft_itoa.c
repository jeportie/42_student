/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JeromeP <JeromeP@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 23:54:37 by JeromeP           #+#    #+#             */
/*   Updated: 2023/09/29 00:28:59 by JeromeP          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_intlen(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	char	*res;
	long 	nbr;
	int		len;

	nbr = (long)nb;
	len = ft_intlen(nbr);
	if (nbr < 0)
		len++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		res[0] = '0';
	while (nbr)
	{
		res[len - 1] = nbr % 10 + '0';
		len--;
		nbr /= 10;
	}
	return (res);
}

#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char 	*res;
	int		a;

	a = 0;
	res = ft_itoa(a);
	printf("result : %s\n", res);
	free(res);
	return(0);
}
