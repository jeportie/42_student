/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_testlst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:45:24 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/28 03:50:26 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"
#include <stdio.h>

void	ft_print_testlst(t_tstlst *lst)
{
	printf("List display:\n\n");
	while (lst->next)
	{
		printf("%s\t%s\t%s\n", lst->title, lst->test_value, lst->description);
		lst = lst->next;
	}
}
