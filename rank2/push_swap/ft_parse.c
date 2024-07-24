/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:09:37 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/24 12:12:19 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_check_empty_args(int ac, char **av)
{
	char	*arg;

	if (ac >= 2)
	{
		arg = av[1];
		while (*arg)
		{
			if (*arg != ' ')
				return ;
			arg++;
		}
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

char	*ft_join_arguments(int ac, char **av)
{
	char	*joined_args;
	char	*temp;
	int		i;

	if (ac < 2)
		return (NULL);
	temp = NULL;
	joined_args = ft_strjoin("", av[1]);
	i = 2;
	while (i < ac)
	{
		temp = ft_strjoin(joined_args, " ");
		free(joined_args);
		if (av[i])
			joined_args = ft_strjoin(temp, av[i]);
		else
			i++;
		free(temp);
		i++;
	}
	return (joined_args);
}
