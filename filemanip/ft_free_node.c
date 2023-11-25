/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:49:56 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/25 16:50:56 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filemanip.h"

void		ft_free_node(void *node)
{
	t_tstlst *test_node;

	test_node = (t_tstlst *)node;
	free(test_node->title);
	free(test_node->test_value);
	free(test_node->description);
	free(test_node);
}
