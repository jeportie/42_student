/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testlst_delone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:05:19 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/28 12:41:01 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftest.h"

static void ft_free_values(char **values)
{
	int	i;

	if (!values)
		return ;
	i = 0;
	while (i < 3)
	{
		free(values[i]);
		i++;
	}
	free(values);
}

void	ft_testlst_delone(t_tstlst *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->title);
	ft_free_values(lst->test_values);
	del(lst->description);
	free(lst);
}
