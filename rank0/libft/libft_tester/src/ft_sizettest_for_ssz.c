/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizettest_for_ssz.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:01:12 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/28 12:39:21 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftest.h"

void ft_sizettest_for_ssz(size_t (*libc_func)(), size_t (*ft_func)(), t_tstlst *lst)
{
    int     result; 
    int     ft_result;
    char    *value1;
    char    *value2;
    size_t  value3;

    if (!ft_strncmp("NULL", lst->test_values[0], 4))
        value1 = NULL;
    else
        value1 = ft_testfile_option_format(lst->test_values[0]);
    if (!ft_strncmp("NULL", lst->test_values[1], 4))
        value2 = NULL;
    else
        value2 = ft_testfile_option_format(lst->test_values[1]);
    value3 = ft_atoi(ft_testfile_option_format(lst->test_values[2]));
    result = ft_sizettester_ssz(libc_func, value1, value2, value3);
    ft_result = ft_sizettester_ssz(ft_func, value1, value2, value3);
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
            printf("%zu\n\tlibc_value: ", (size_t)ft_result);
        if (result == SEGFAULT)
            printf("SEGFAULT\n");
        else
            printf("%zu\n", (size_t)result);
    }
}
