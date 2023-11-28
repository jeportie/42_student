/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testlst_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:47:53 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/28 03:50:56 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

static void ft_free_content(char *s1, char *s2, char *s3)
{
	free(s1);
	free(s2);
	free(s3);
}

t_tstlst	*ft_testlst_new(char *title, char *value, char *description)
{
	t_tstlst	*node;
	char		*node_title;
	char		*node_value;
	char		*node_description;

	node_title = ft_strdup(title);
	node_value = ft_strdup(value);
	node_description = ft_strdup(description);
	if (!node_title || !node_value || !node_description)
	{
		ft_free_content(node_title, node_value, node_description);
		return (NULL);
	}
	node = (t_tstlst *)malloc(sizeof(t_tstlst));
	if (!node)
	{
		ft_free_content(node_title, node_value, node_description);
		return (NULL);
	}
	node->title = node_title;
	node->test_value = node_value;
	node->description = node_description;
	node->next = NULL;
	return (node);
}
