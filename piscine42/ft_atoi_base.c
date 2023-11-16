/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JeromeP <JeromeP@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:51:34 by JeromeP           #+#    #+#             */
/*   Updated: 2023/09/28 23:51:01 by JeromeP          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_issign(char c, int *sign)
{
	if (c == '-')
	{
		*sign *= -1;
		return (1);
	}
	if (c == '+')
		return(1);
	return (0);
}

//pas de double, pas de + ou de -, au moins 2 char dans la base)
int	ft_checkbase(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	digit;
	int	result;
	int	sign;
	int	base_len;

	base_len = ft_checkbase(base);
	if (!base_len)
		return (0);
	i = 0;
	result = 0;
	sign = 1;
	while(ft_issign(str[i], &sign))
		i++;
	while(str[i])
	{
		digit = 0;
		while (base[digit] && base[digit] != str[i])
			digit++;
		if (base[digit] == '\0')
			break;
		result = result * base_len + digit;
		i++;
	}
	return (sign * result);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	printf("result : %d\n", ft_atoi_base(argv[1], argv[2]));
	return (0);
}
