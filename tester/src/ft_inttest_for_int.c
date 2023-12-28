/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttest_for_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:15:23 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/28 12:37:56 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftest.h"

/*
 * Tests integer-returning functions with a single integer argument.
 * Handles special values like NULL, INT_MIN, INT_MAX, and compares libc and ft function results.
 */

void ft_inttest_for_int(int (*libc_func)(), int (*ft_func)(), t_tstlst *lst)
{
    int result; 
    int ft_result;
    int value;

    if (!ft_strncmp("NULL", lst->test_values[0], 4))
        value = 0;
    else if (!ft_strncmp("INT_MIN", lst->test_values[0], 7))
        value = INT_MIN;
    else if (!ft_strncmp("INT_MAX", lst->test_values[0], 7))
       value = INT_MAX;
    else
        value = ft_atoi(ft_testfile_option_format(lst->test_values[0]));
    result = ft_inttester_int(libc_func, value);
    ft_result = ft_inttester_int(ft_func, value);
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
