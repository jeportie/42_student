/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtester_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:27:09 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/28 12:40:24 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftest.h"

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
