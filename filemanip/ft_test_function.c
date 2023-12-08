/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:07:14 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/08 19:34:18 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

static int  ft_exec_and_segfaultcheck(int (*f)(), int value)
{
    pid_t   pid;
    int     status;

    pid = fork();
    if (pid == -1)
    {
        perror("forking failed.");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        signal(SIGSEGV, SIG_DFL);
        f(value);
        exit(EXIT_SUCCESS);
    }
    else
    {
        waitpid(pid, &status, 0);
        if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
            return (-1);
        else
            return (f(value));
    }
}

static void ft_display_seg(int (*libc_func)(), int (*ft_func)(), int value, t_tstlst *lst)
{
    int result; 
    int ft_result;

    result = ft_exec_and_segfaultcheck(libc_func, value);
    ft_result = ft_exec_and_segfaultcheck(ft_func, value);
    if (ft_result == result)
        printf("%s: OK!\n", lst->title);
    if (result == -1 && ft_result == -1)
        printf("%s: Segfaults as expected!\n", lst->title);
    else
    {
        printf("%s: KO! -> %s\n", lst->title, lst->description);
        printf("\tft_value:%i\n\tlibc_value:%i\n", ft_result, result);
        printf("\tif -1 -> SEGFAULT\n");
    }
}

void ft_test_function(t_tstlst *lst, int (*libc_func)(), int (*ft_func)(), t_arg arg_type)
{
    int result;
    int ft_result;

    if (!ft_strncmp("NULL", lst->test_values[0], 4))
        ft_display_seg(libc_func, ft_func, 0, lst);
    else if (!ft_strncmp("INT_MIN", lst->test_values[0], 7))
        ft_display_seg(libc_func, ft_func, INT_MIN, lst);
    else if (!ft_strncmp("INT_MAX", lst->test_values[0], 7))
       ft_display_seg(libc_func, ft_func, INT_MAX, lst);
    else
    {
        if (arg_type == ARG_INT)
        {
            result = libc_func(ft_atoi(ft_testfile_option_format(lst->test_values[0])));
            ft_result = ft_func(ft_atoi(ft_testfile_option_format(lst->test_values[0])));
        }
        else
        {
            result = libc_func(ft_testfile_option_format(lst->test_values[0]));
            ft_result = ft_func(ft_testfile_option_format(lst->test_values[0]));
        }
        if (ft_result == result)
            printf("%s: OK!\n", lst->title);
        else
        {
            printf("%s: KO! -> %s\n", lst->title, lst->description);
            printf("\tft_value:%i\n\tlibc_value:%i\n", ft_result, result);
        }
    }
}
