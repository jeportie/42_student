/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:36:52 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/05 13:14:05 by jeportie         ###   ########.fr       */
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

/*Redundant Reading of File: Reading the file twice - once in 
 *ft_flines_to_str and again in ft_count_flines. This could be optimized. 
 *Ideally, should read the file only once and then both count the lines 
 *and split them. This optimization will improve efficiency, especially for 
 *large files.*/
