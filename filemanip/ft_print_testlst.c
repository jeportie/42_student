/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_testlst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:45:24 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/07 13:41:10 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"
#include <stdio.h>

void	ft_print_testlst(t_tstlst *lst)
{
	char	*value1;
	char	*value2;
	char	*value3;

	printf("List display:\n\n");
	while (lst->next)
	{
		value1 = lst->test_values[0];
		value2 = lst->test_values[1];
		value3 = lst->test_values[2];
		printf("Test1:\nTitle:%s\nValue1:%s\nValue2:%s\nValue3:%s\nDescription:%s:\n", lst->title, value1, value2, value3, lst->description);
		lst = lst->next;
	}
}
