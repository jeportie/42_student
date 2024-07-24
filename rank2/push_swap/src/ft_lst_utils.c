/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:31:50 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/24 14:34:02 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_mid_stack(t_stack *lst)
{
	int	mid;

	mid = ft_stack_size(lst) / 2;
	return (mid);
}

t_stack	*ft_stacknew(long nb)
{
	t_stack	*new;

	new = malloc(1 * sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

void	ft_stackadd_back(t_stack **lst, t_stack *New)
{
	t_stack	*tmp;

	if (!(*lst) && New)
		*lst = New;
	else if (*lst && New)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = New;
	}
}

t_stack	*ft_stacklast(t_stack *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	else
		return (NULL);
	return (lst);
}

t_stack	*ft_before_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}
