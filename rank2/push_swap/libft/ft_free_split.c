/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:53:08 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/24 15:27:55 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_free_split(char **split, int size)
{
	int	i;

	i = 0;
	if (split)
	{
		while (i < size)
		{
			free(split[i]);
			i++;
		}
		free(split);
		split = NULL;
	}
}
