/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttest_for_vvz.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:16:20 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/28 12:38:19 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftest.h"

/*
 * Tests integer-returning functions with two void pointers and a size_t argument.
 * Handles NULL inputs for the void pointers and compares libc and ft function results.
 */

void ft_inttest_for_vvz(int (*libc_func)(), int (*ft_func)(), t_tstlst *lst)
{
    int     result; 
    int     ft_result;
    void    *value1;
    void    *value2;
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
    result = ft_inttester_vvz(libc_func, value1, value2, value3);
    ft_result = ft_inttester_vvz(ft_func, value1, value2, value3);
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
            printf("%i\n\tlibc_value: ", ft_result);
        if (result == SEGFAULT)
            printf("SEGFAULT\n");
        else
            printf("%i\n", result);
    }
}
