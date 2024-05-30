/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:22:10 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/22 18:23:32 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_split(char **argv)
{
	char	**tmp;

	tmp = argv;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(argv);
}
