/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:39:41 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/21 01:57:51 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *New)
{
	t_list	*last;

	if (!lst || !New)
		return ;
	if (!*lst)
	{
		*lst = New;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = New;
}
