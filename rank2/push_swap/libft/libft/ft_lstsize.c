/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:21:54 by neleon            #+#    #+#             */
/*   Updated: 2023/11/30 19:50:05 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	node;

	node = 0;
	while (lst)
	{
		lst = lst->next;
		node++;
	}
	return (node);
}

// int	main(void)
// {
// 	t_list *node1 = ft_lstnew((void *)1);
// 	t_list *node2 = ft_lstnew((void *)2);
// 	t_list *node3 = ft_lstnew((void *)2);

// 	ft_lstadd_front(&node1, node2);
// 	ft_lstadd_front(&node2, node3);

// 	int size = ft_lstsize(node3);

// 	printf("List size is: %d\n", size);
// }