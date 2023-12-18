/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizettest_for_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:56:27 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/18 14:00:13 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

void ft_sizettest_for_str(size_t (*libc_func)(), size_t (*ft_func)(), t_tstlst *lst)
{
    size_t		result; 
    size_t		ft_result;
    char		*value;

    if (!ft_strncmp("NULL", lst->test_values[0], 4))
        value = NULL;
    else
        value = ft_testfile_option_format(lst->test_values[0]);
    result = ft_sizettester_str(libc_func, value);
    ft_result = ft_sizettester_str(ft_func, value);
    if (ft_result == result)
        printf("%s: OK!\n", lst->title);
    if (result == SEGFAULT && ft_result == SEGFAULT)
        printf("%s: Segfaults as expected!\n", lst->title);
    if (ft_result != result)
    {
        printf("%s: KO! -> %s\n", lst->title, lst->description);
        printf("\tft_value: ");
        if (ft_result == SEGFAULT)
            printf("SEGFAULT\n\tlibcvalue: ");
        else
            printf("%zu\n\tlibc_value: ", ft_result);
        if (result == SEGFAULT)
            printf("SEGFAULT\n");
        else
            printf("%zu\n", result);
    }
}
