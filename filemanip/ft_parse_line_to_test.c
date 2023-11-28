/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line_to_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:47:39 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/29 00:54:08 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

t_tstlst	*ft_parse_line_to_test(const char *line)
{
	t_tstlst	*node;
	char		**splits;
	
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
	node = ft_testlst_new(splits[0], splits[1], splits[2]);
	ft_free_memory(splits, 3); /*assuming ft_testlst_new duplicates the strings*/
	return (node);
}
