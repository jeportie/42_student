/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartest_for_si.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:20:11 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/27 18:22:17 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

/*
 * Tests string-returning functions with a string and an integer argument.
 * Handles NULL inputs, compares results, and reports discrepancies.
 */

void ft_chartest_for_si(char *(*libc_func)(), char *(*ft_func)(), t_tstlst *lst)
{
    char    *result; 
    char    *ft_result;
    char    *value1;
    int     value2;

    if (!ft_strncmp("NULL", lst->test_values[0], 4))
        value1 = NULL;
    else
        value1 = ft_testfile_option_format(lst->test_values[0]);
    value2 = ft_atoi(ft_testfile_option_format(lst->test_values[1]));

    result = ft_strtester_si(libc_func, value1, value2);
    ft_result = ft_strtester_si(ft_func, value1, value2);
    if ((!ft_result && !result) || (ft_result && result && !strcmp(ft_result, result)))
        printf("%s: OK!\n", lst->title);
    if (result && !strcmp(result, "segfault") && ft_result && !strcmp(ft_result, "segfault"))
        printf("%s: Segfaults as expected!\n", lst->title);
    if ((!result && ft_result) || (result && !ft_result) || (result && ft_result && strcmp(ft_result, result)))
    {
        printf("%s: KO! -> %s\n", lst->title, lst->description);
        printf("\tft_value: ");
        if (ft_result && !strcmp(ft_result, "segfault"))
            printf("SEGFAULT\n\tlibc_value: ");
        else if (ft_result)
            printf("%s\n\tlibc_value: ", ft_result);
        else
            printf("NULL\n\tlibc_value: ");
        if (result && !strcmp(result, "segfault"))
            printf("SEGFAULT\n");
        else if (result)
            printf("%s\n", result);
        else
            printf("NULL\n");
    }
}
