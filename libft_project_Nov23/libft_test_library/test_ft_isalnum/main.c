/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:37:04 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/08 18:12:52 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../function_libraries/libfmanip.h"
#include "../function_libraries/libft.h"

int	main(void)
{
	t_tstlst	*lst;
	int		i;

	lst = ft_load_tests("ft_isalnum_test_data.txt");
	if (!lst)
		exit(EXIT_FAILURE);
	i = 1;
	printf("FT_ISALNUM TEST:\n");
	while (lst->next)
	{
        ft_test_function(lst, i, isalnum, ft_isalnum);
		i++;
		lst = lst->next;
	}
	ft_test_function(lst, i, isalnum, ft_isalnum);
    return (0);
}
