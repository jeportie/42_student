/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_test_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:08:27 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/13 11:59:46 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

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

void ft_chartest_for_ssz(char *(*libc_func)(), char *(*ft_func)(), t_tstlst *lst)
{
    char    *result;
    char    *ft_result;
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
    result = ft_strtester_ssz(libc_func, value1, value2, value3);
    ft_result = ft_strtester_ssz(ft_func, value1, value2, value3);
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
