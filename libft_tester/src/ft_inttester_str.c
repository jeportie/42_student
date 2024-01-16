/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttester_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:30:02 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/28 12:38:41 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftest.h"

int  ft_inttester_str(int (*f)(), char *value)
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
            return (SEGFAULT);
        else
            return (f(value));
    }
}
