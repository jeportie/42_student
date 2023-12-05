/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testlst_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:47:53 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/05 17:08:56 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

static void ft_free_content(char *s1, char **test_values, char *s3)
{
	free(s1);
	ft_free_memory(test_values, 3);
	free(s3);
}

t_tstlst	*ft_testlst_new(char *title, char **values, char *description)
{
	t_tstlst	*node;
	char		*node_title;
	char		**node_values;
	char		*node_description;

	node_title = ft_strdup(title);
	node_values = (char **)malloc(sizeof(char *) * 3);
	node_values[0] = ft_strdup(values[0]);
	node_values[1] = ft_strdup(values[1]);
	node_values[2] = ft_strdup(values[2]);
	node_description = ft_strdup(description);
	if (!node_title || !node_values || !node_description)
	{
		ft_free_content(node_title, node_values, node_description);
		return (NULL);
	}
	node = (t_tstlst *)malloc(sizeof(t_tstlst));
	if (!node)
	{
		ft_free_content(node_title, node_values, node_description);
		return (NULL);
	}
	node->title = node_title;
	node->test_values = node_values;
	node->description = node_description;
	node->next = NULL;
	return (node);
}
