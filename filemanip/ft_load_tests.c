/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:36:52 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/29 00:54:32 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"
#include <stdlib.h>

t_tstlst	*ft_load_tests(const char *filepath)
{
	char 		**fextract;
	size_t		lst_size;
	size_t		i;
	t_tstlst	*data_lst;
	t_tstlst	*data_node;

	fextract = ft_flines_to_str(filepath);
	if (!fextract)
		return (NULL);
	lst_size = (size_t)ft_count_flines(filepath);
	data_lst = NULL;
	i = 0;
	while (i < lst_size)
	{
		data_node = ft_parse_line_to_test(fextract[i]);
		if (!data_node)
		{
			ft_testlst_clear(&data_lst, ft_free_node);
			break;
		}
		ft_testlst_add_back(&data_lst, data_node);
		i++;
	}
	ft_free_memory(fextract, lst_size);
	return (data_lst); 
}

char	*ft_testfile_option_format(char *s)
{
//	if (!ft_strncmp("NULL", s, 5))
//		return (NULL);
	if (!ft_strncmp("EMPTY", s, 6))
		return ("");
	else if (!ft_strncmp("SPACE", s, 6))
		return ("         ");
	else
		return (s);
}
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
/*Redundant Reading of File: Reading the file twice - once in 
 *ft_flines_to_str and again in ft_count_flines. This could be optimized. 
 *Ideally, should read the file only once and then both count the lines 
 *and split them. This optimization will improve efficiency, especially for 
 *large files.*/
