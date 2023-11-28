/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testlst_delone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:05:19 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/28 03:57:44 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

void	ft_testlst_delone(t_tstlst *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->title);
	del(lst->test_value);
	del(lst->description);
	free(lst);
}
