/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:49:56 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/28 12:37:49 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftest.h"

static int	ft_count_values(char **values)
{
	int	nb;

	nb = 0;
	while(values && values[nb])
		nb++;
	return (nb);
}

void		ft_free_node(void *node)
{
	t_tstlst	*test_node;
	int			i;

	test_node = (t_tstlst *)node;
	i = ft_count_values(test_node->test_values);
	free(test_node->title);
	ft_free_memory(test_node->test_values, i);
	free(test_node->description);
	free(test_node);
}
