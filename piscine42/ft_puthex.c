/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JeromeP <JeromeP@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 00:33:04 by JeromeP           #+#    #+#             */
/*   Updated: 2023/09/29 00:59:29 by JeromeP          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	ft_puthex(char *str)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	while (str[i])
	{
		ft_putchar(base[(unsigned char)str[i] / 16]);
		ft_putchar(base[(unsigned char)str[i] % 16]);
		if ((i + 1) % 2 == 0)
			ft_putchar(' ');
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	ft_puthex(argv[1]);
	return (0);
}
