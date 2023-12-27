/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testlst_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:47:53 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/07 12:00:58 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

static void ft_free_content(char *s1, char **test_values, int num_values, 
		char *s3)
{
	free(s1);
	ft_free_memory(test_values, num_values);
	free(s3);
}

static char **ft_duplicate_values(char **values, int num_values)
{
	char	**node_values;
	int		i;

	node_values = (char **)malloc(sizeof(char *) * num_values);
	if (!node_values)
		return (NULL);
	i = 0;
	while (i < num_values)
	{
		node_values[i] = ft_strdup(values[i]);
		if (!node_values[i])
		{
			ft_free_memory(node_values, i);
			return (NULL);
		}
		i++;
	}
	return (node_values);
}

t_tstlst	*ft_testlst_new(char *title, char **values, int num_values, 
		char *description)
{
	t_tstlst	*node;
	char		*node_title;
	char		**node_values;
	char		*node_description;

	node_title = ft_strdup(title);
	node_description = ft_strdup(description);
	node_values = ft_duplicate_values(values, num_values);
	if (!node_title || !node_values || !node_description)
	{
		ft_free_content(node_title, node_values, num_values, node_description);
		return (NULL);
	}
	node = (t_tstlst *)malloc(sizeof(t_tstlst));
	if (!node)
	{
		ft_free_content(node_title, node_values, num_values, node_description);
		return (NULL);
	}
	node->title = node_title;
	node->test_values = node_values;
	node->description = node_description;
	node->next = NULL;
	return (node);
}
