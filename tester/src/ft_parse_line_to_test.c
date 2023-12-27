/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line_to_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:47:39 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/07 02:40:34 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

static int	ft_count_values(char **values)
{
	int	nb;

	nb = 0;
	while(values && values[nb])
		nb++;
	return (nb);
}

t_tstlst	*ft_parse_line_to_test(const char *line)
{
	t_tstlst	*node;
	int			nb_values;
	char		**splits;
	char		**values;
	
	if (!line)
		return (NULL);
	splits = ft_split(line, ':');
	if (!splits)
		return (NULL);
	if (!splits[0] || !splits[1] || !splits[2])
	{
		ft_free_memory(splits, 3);
		return (NULL);
	}
	values = ft_split(splits[1], ',');
	if (!values)
		return (NULL);
	nb_values = ft_count_values(values);
	node = ft_testlst_new(splits[0], values, nb_values, splits[2]);
	ft_free_memory(splits, 3);
	ft_free_memory(values, nb_values);
	return (node);
}
