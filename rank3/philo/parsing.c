/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:52:27 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/15 17:55:25 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_issign(int c, int *sign)
{
	if (c == '+')
		return (1);
	if (c == '-')
	{
		*sign *= -1;
		return (1);
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

bool	ft_is_int(char *nptr)
{
	int	len;
	int	i;
	int	sign;

	len = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (ft_issign(nptr[i], &sign))
		i++;
	while (nptr[i] == '0')
		i++;
	while (nptr[len + i])
	{
		if (!ft_isdigit(nptr[len + i]))
			return (false);
		len++;
	}
	if (len < 10)
		return (true);
	if (len == 10)
	{
		if (sign == -1)
		{
			if (ft_strncmp(&nptr[i], "2147483648", 10) > 0)
				return (false);
		}
		else
		{
			if (ft_strncmp(&nptr[i], "2147483647", 10) > 0)
				return (false);
		}
	}
	return (true);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	digit;
	int	sign;
	int	i;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (ft_issign(nptr[i], &sign))
		i++;
	while (ft_isdigit(nptr[i]))
	{
		digit = nptr[i] - '0';
		result = result * 10 + digit;
		i++;
	}
	return (result * sign);
}

