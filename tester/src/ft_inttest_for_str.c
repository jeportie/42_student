/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttest_for_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:15:56 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/28 12:38:10 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftest.h"

/*
 * Tests integer-returning functions with a single string argument.
 * Handles NULL inputs and compares the results from libc and ft implementations.
 */

void ft_inttest_for_str(int (*libc_func)(), int (*ft_func)(), t_tstlst *lst)
{
    int     result; 
    int     ft_result;
    char    *value;

    if (!ft_strncmp("NULL", lst->test_values[0], 4))
        value = NULL;
    else
        value = ft_testfile_option_format(lst->test_values[0]);
    result = ft_inttester_str(libc_func, value);
    ft_result = ft_inttester_str(ft_func, value);
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
