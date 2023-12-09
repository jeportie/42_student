/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JeromeP <JeromeP@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:21:56 by JeromeP           #+#    #+#             */
/*   Updated: 2023/12/09 11:54:40 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../function_libraries/libfmanip.h"
#include "../function_libraries/libft.h"

int	main(void)
{
	t_tstlst	*lst;
	int			i;

	lst = ft_load_tests("ft_atoi_test_data.txt");
	if (!lst)
		exit(EXIT_FAILURE);
	i = 1;
	printf("FT_ATOI TEST:\n");
	while (lst->next)
	{
		printf("Test %i: ", i);
        ft_test_function(lst, atoi, ft_atoi, ARG_STRING);
		i++;
		lst = lst->next;
	}
	ft_test_function(lst, atoi, ft_atoi, ARG_STRING);
    return (0);
}
