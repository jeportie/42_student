/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartest_for_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:21:38 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/27 18:22:02 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

/* 
 * Tests string-returning functions with a single string argument.
 * Compares the results of the libc and ft implementations, handling segfaults.
 */

void ft_chartest_for_str(func_str libc_func, func_str ft_func, t_tstlst *lst)
{
    char    *result; 
    char    *ft_result;
    char    *value;

    if (!ft_strncmp("NULL", lst->test_values[0], 4))
        value = NULL;
    else
        value = ft_testfile_option_format(lst->test_values[0]);
    result = ft_strtester_str(libc_func, value);
    ft_result = ft_strtester_str(ft_func, value);
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
