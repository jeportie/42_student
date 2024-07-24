/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:29:36 by neleon            #+#    #+#             */
/*   Updated: 2023/12/05 17:26:44 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_nb_size(long nb)
{
	long	size;
	long	sign;

	size = 0;
	sign = 1;
	if (nb < 0)
	{
		sign = -sign;
		nb = -nb;
		size++;
	}
	else if (nb == 0)
		return (1);
	while (nb != 0)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

static void	ft_nbr_to_str(long nb, char *itoa, long size)
{
	if (nb < 0)
	{
		itoa[0] = '-';
		nb *= -1;
	}
	if (nb > 9)
		ft_nbr_to_str(nb / 10, itoa, size - 1);
	itoa[size] = nb % 10 + '0';
}

char	*ft_itoa(int n)
{
	long	nb;
	long	size;
	char	*itoa;

	nb = n;
	size = ft_nb_size(nb);
	itoa = (char *)malloc((size + 1) * sizeof(char));
	if (!itoa)
		return (NULL);
	if (nb < 0)
		itoa[0] = '-';
	ft_nbr_to_str(nb, itoa, size - 1);
	itoa[size] = '\0';
	return (itoa);
}

// int main(void)
// {
//     char *itoa;

//     int nb = -1234504922;
//     itoa = ft_itoa(nb);
//     long size = ft_nb_size(nb);
//     printf("Nb size is: %ld\n", size);
//     printf("itoa is: %s\n", itoa);
// 	free(itoa);
//     return (0);
// }