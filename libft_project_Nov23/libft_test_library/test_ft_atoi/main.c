/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JeromeP <JeromeP@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:21:56 by JeromeP           #+#    #+#             */
/*   Updated: 2023/12/05 13:12:12 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"
#include "libft.h"

int	main(void)
{
	t_tstlst	*lst;
	int			ft_result;
	int			result;
	int		i;

	lst = ft_load_tests("ft_atoi_test_data.txt");
	if (!lst)
		exit(EXIT_FAILURE);
	i = 1;
	printf("FT_ATOI TEST:\n");
	while (lst->next)
	{
		result = atoi(ft_testfile_option_format(lst->test_value));
		ft_result = ft_atoi(ft_testfile_option_format(lst->test_value));
		if (ft_result == result)
			printf("Test%d: %s: OK!\n", i, lst->title);
		else
		{
			printf("Test%d: %s: KO! -> %s\n", i,lst->title, lst->description);
			printf("\tft_value:%i\n\tlibc_value:%i\n", ft_result, result);
		}
		i++;
		lst = lst->next;
	}
	return (0);
}
