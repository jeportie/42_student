/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testlst_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:04:58 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/28 12:40:54 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftest.h"

void	ft_testlst_clear(t_tstlst **lst, void (*del)(void *))
{
	t_tstlst	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_testlst_delone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
