/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:19:20 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/13 13:40:36 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

/* 
 * Tests a string-returning function for segmentation faults.
 * Forks a process to isolate the function call and checks for a segfault signal.
 */

char *ft_strtester_str(char *(*f)(), char *value)
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
            return ("segfault");
        else
            return (f(value));
    }
}

char *ft_strtester_si(char *(*f)(), char *value1, int value2)
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
        f(value1, value2);
        exit(EXIT_SUCCESS);
    }
    else
    {
        waitpid(pid, &status, 0);
        if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
            return ("segfault");
        else
            return (f(value1, value2));
    }
}

char	*ft_strtester_ssz(char *(*f)(), char *value1, char *value2, size_t value3)
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
        f(value1, value2, value3);
        exit(EXIT_SUCCESS);
    }
    else
    {
        waitpid(pid, &status, 0);
        if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
            return ("segfault");
        else
            return (f(value1, value2, value3));
    }
}
